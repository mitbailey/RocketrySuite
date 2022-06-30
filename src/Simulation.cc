/**
 * @file Simulation.cc
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief
 * @version See Git tags for version information.
 * @date 2022.04.23
 *
 * @copyright Copyright (c) 2022
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 */

#include "Simulation.hcc"
#include "common.hcc"
#include "math.h"
#include "meb_print.h"
#include <string.h>

// Simulation::Simulation(Vehicle *vehicle, Conditions *conditions)
// {
//     this->vehicle = vehicle;
//     this->conditions = conditions;
//     memset(simState, 0x0, sizeof(sim_state_t));
// }

Simulation::Simulation()
{
    this->vehicle = new Vehicle();
    this->conditions = new Conditions();

    memset(simState, 0x0, sizeof(sim_state_t));
}

Simulation::~Simulation()
{
    delete vehicle;
    delete conditions;
}

// Vehicle *Simulation::AttachVehicle(Vehicle *vehicle)
// {
//     Vehicle *old_vehicle = this->vehicle;
//     this->vehicle = vehicle;
//     return old_vehicle;
// }

// Conditions *Simulation::AttachConditions(Conditions *conditions)
// {
//     Conditions *old_conditions = this->conditions;
//     this->conditions = conditions;
//     return old_conditions;
// }

void Simulation::Simulate()
{
    PerformCalculations();
    DisplaySimState();
}

double Simulation::CalculateLaunchAngle()
{
    PerformCalculations();

    // calculateVelocityMax();
    // calculateDeploymentAltitudeA();

    // Finding the angle mathematically is incredibly difficult.
    // Instead, I find it iteratively.
    double proposedRange = 0;
    double proposedAngle = 90;
    while ((proposedRange < simState->drift - 0.001 || proposedRange > simState->drift + 0.001) && proposedAngle > 45)
    {
        proposedRange = (simState->altitude_boost * (cos(proposedAngle / (180 / M_PI)))) + ((pow(simState->velocity_terminal, 2) / g) * log((pow(simState->velocity_terminal, 2) + g * (simState->velocity_max * (cos(proposedAngle / (180 / M_PI)))) * vehicle->parachute->deploymentTime) / (pow(simState->velocity_terminal, 2))));
        proposedAngle -= 0.000001;
    }
    launchAngle = proposedAngle;

    dbprintlf("Calculated launch angle: %.03f", proposedAngle);

    return launchAngle;
}

void Simulation::PerformCalculations()
{
    if (vehicle == nullptr || vehicle == NULL)
    {
        bprintlf(RED_FG "No vehicle selected!");
        return;
    }
    else if (conditions == nullptr || conditions == NULL)
    {
        bprintlf(RED_FG "No weather conditions set!");
        return;
    }

    // Ensure air density is calculated.
    conditions->CalculateSetAirDensity();

    // Calculate average mass and thrust.
    double avg_mass = ((vehicle->massEmpty + vehicle->engine->massLoaded) + (vehicle->massEmpty + vehicle->engine->massEmpty)) / 2.0;
    double avg_thrust = vehicle->engine->CalculateAverageThrust();

    // Calculate K, Q, and X.
    double K = 0.5 * conditions->airDensity * vehicle->dragCoefficient * vehicle->crossSectionalArea;

    if (avg_thrust - (avg_mass * g) < 0)
    {
        bprintlf(RED_FG "ERROR: Average thrust (%.03f) is less than the average mass times g (%.03f).", avg_mass, avg_mass * g);
        return;
    }

    double Q = sqrt((avg_thrust - (avg_mass * g)) / K);
    double X = (2 * K * Q) / avg_mass;

    // Calculate maximum velocity during powered ascent.
    double velocity_max = Q * ((1 - exp(-X * vehicle->engine->burnTime)) / (1 + std::exp(-X * vehicle->engine->burnTime)));

    // Calculate altitude boost, the altitude gained during powered ascent.
    double Z = avg_thrust - avg_mass * g;
    double Y = K * velocity_max * velocity_max;

    double altitude_boost = (-avg_mass / (2 * K)) * log((Z - Y) / (Z));

    // Calculate descent speed under parachute.
    double descent_speed = vehicle->parachute->CalculateSetDescentSpeed(vehicle->massEmpty + vehicle->engine->massEmpty, conditions->airDensity);

    /* Angle-based calculations. */
    double mass_coast = vehicle->massEmpty + vehicle->engine->massEmpty;
    double mg = mass_coast * g;

    // calculateVelocityMaxXA();
    double velocity_max_x_a = velocity_max * (cos(launchAngle / (180.f / M_PI)));

    // calculateVelocityMaxYA();
    double velocity_max_y_a = velocity_max * (sin(launchAngle / (180.f / M_PI)));

    // calculateAltitudeBoostA();
    double altitude_boost_a = altitude_boost * (sin(launchAngle / (180.f / M_PI)));

    // calculateVelocityTerminal();
    double velocity_terminal = sqrt((2 * mg) / (vehicle->dragCoefficient * conditions->airDensity * vehicle->crossSectionalArea));

    // calculateHeightCoastA();
    double height_coast_a = ((pow(velocity_terminal, 2)) / (2 * g)) * log((pow(velocity_max_y_a, 2) + pow(velocity_terminal, 2)) / (pow(velocity_terminal, 2)));

    // calculateAltitudeMaxA();
    double altitude_max_a = height_coast_a + altitude_boost_a;

    // calculateTimeMECOToAPA();
    double time_meco_to_ap_a = velocity_max_y_a / g;

    // calculateTimeAPToDeploymentA();
    double time_ap_to_deployment_a = vehicle->parachute->deploymentTime - (vehicle->engine->burnTime + time_meco_to_ap_a);

    // calculateDeploymentAltitudeA();
    double deployment_altitude_a = altitude_max_a - (0.5 * g * pow(time_ap_to_deployment_a, 2));

    // calculateTimeDeploymentToGroundA();
    double time_deployment_to_ground_a = deployment_altitude_a / vehicle->parachute->landingVelocity;

    // calculateDeploymentVelocityA();
    double deployment_velocity_a = g * time_ap_to_deployment_a;

    // calculateTimeOfFlightA();
    double time_of_flight_a = vehicle->engine->burnTime + time_meco_to_ap_a + time_ap_to_deployment_a + time_deployment_to_ground_a;

    // calculateDrift();
    double drift = deployment_altitude_a / (vehicle->parachute->landingVelocity / conditions->windspeed);

    // calculateRangeBoost();
    double range_boost = altitude_boost * (cos(launchAngle / (180.f / M_PI)));

    // calculateRangeCoast();
    double range_coast = (pow(velocity_terminal, 2) / g) * log((pow(velocity_terminal, 2) + g * velocity_max_x_a * vehicle->parachute->deploymentTime) / (pow(velocity_terminal, 2)));

    // calculateRange();
    double range = range_boost + range_coast;

    // dbprintlf(BLUE_FG "%.03f", avg_mass);
    // dbprintlf(BLUE_FG "%.03f", avg_thrust);
    // dbprintlf(BLUE_FG "%.03f", K);
    // dbprintlf(BLUE_FG "%.03f", Q);
    // dbprintlf(BLUE_FG "%.03f", X);
    // dbprintlf(BLUE_FG "%.03f", velocity_max);
    // dbprintlf(BLUE_FG "%.03f", Z);
    // dbprintlf(BLUE_FG "%.03f", Y);
    // dbprintlf(BLUE_FG "%.03f", altitude_boost);
    // dbprintlf(BLUE_FG "%.03f", descent_speed);
    // dbprintlf(BLUE_FG "%.03f", mass_coast);
    // dbprintlf(BLUE_FG "%.03f", velocity_max_x_a);
    // dbprintlf(BLUE_FG "%.03f", velocity_max_y_a);
    // dbprintlf(BLUE_FG "%.03f", altitude_boost_a);
    // dbprintlf(BLUE_FG "%.03f", velocity_terminal);
    // dbprintlf(BLUE_FG "%.03f", height_coast_a);
    // dbprintlf(BLUE_FG "%.03f", altitude_max_a);
    // dbprintlf(BLUE_FG "%.03f", time_meco_to_ap_a);

    // TODO: Just set them directly above (for now helps to debug instances where we forget to calculate a value before using it).
    simState->avg_mass = avg_mass;
    simState->avg_thrust = avg_thrust;
    simState->K = K;
    simState->Q = Q;
    simState->X = X;
    simState->velocity_max = velocity_max;
    simState->Z = Z;
    simState->Y = Y;
    simState->altitude_boost = altitude_boost;
    simState->descent_speed = descent_speed;
    simState->mass_coast = mass_coast;
    simState->velocity_max_x_a = velocity_max_x_a;
    simState->velocity_max_y_a = velocity_max_y_a;
    simState->altitude_boost_a = altitude_boost_a;
    simState->velocity_terminal = velocity_terminal;
    simState->height_coast_a = height_coast_a;
    simState->altitude_max_a = altitude_max_a;
    simState->time_meco_to_ap_a = time_meco_to_ap_a;
    simState->time_ap_to_deployment_a = time_ap_to_deployment_a;
    simState->deployment_altitude_a = deployment_altitude_a;
    simState->time_deployment_to_ground_a = time_deployment_to_ground_a;
    simState->deployment_velocity_a = deployment_velocity_a;
    simState->time_of_flight_a = time_of_flight_a;
    simState->drift = drift;
    simState->range_boost = range_boost;
    simState->range_coast = range_coast;
    simState->range = range;
}

void Simulation::DisplaySimState()
{
    bprintlf("SIMULATION COMPLETE, RESULTS...");
    bprintlf("====================================================================\n");
    bprintlf("ALTITUDE~");
    bprintlf("At MECO:             %.03f m", simState->altitude_boost_a);
    bprintlf("Gained during coast: %.03f m", simState->height_coast_a);
    bprintlf("At apogee:           %.03f m", simState->altitude_max_a);
    bprintlf("At deployment:       %.03f m\n", simState->deployment_altitude_a);

    bprintlf("DISTANCE~");
    bprintlf("Range: %.03f m", simState->range);
    bprintlf("Drift: %.03f m\n", simState->drift);

    bprintlf("VELOCITY~");
    bprintlf("Maximum:    %.03f m/s", simState->velocity_max);
    bprintlf("Terminal:   %.03f m/s", simState->velocity_terminal);
    bprintlf("Deployment: %.03f m/s", simState->deployment_velocity_a);
    bprintlf("Landing:    %.03f m/s\n", vehicle->parachute->landingVelocity);

    bprintlf("TIME~");
    bprintlf("Launch to MECO:       %.03f s", vehicle->engine->burnTime);
    bprintlf("MECO to Apogee:       %.03f s", simState->time_meco_to_ap_a);
    bprintlf("Apogee to deployment: %.03f s", simState->time_ap_to_deployment_a);
    bprintlf("Deployment to ground: %.03f s", simState->time_deployment_to_ground_a);
    bprintlf("Total time of flight: %.03f s\n", simState->time_of_flight_a);

    if (abs(simState->range - simState->drift) > 15.f)
    {
        bprintlf(YELLOW_BG "WARNING: Vehicle will land %.03f meters from the launch site!", abs(simState->range - simState->drift));
    }

    if (simState->time_ap_to_deployment_a <= 0.f)
    {
        bprintlf(YELLOW_BG "WARNING: Parachute will deploy %.03f seconds prior to reaching apogee!", simState->time_ap_to_deployment_a);
    }

    if (simState->altitude_max_a < 15.f)
    {
        bprintlf(YELLOW_BG "WARNING: Vehicle apogee %.03f meters!", simState->altitude_max_a);
    }
    else if (simState->altitude_max_a > 300)
    {
        bprintlf(YELLOW_BG "WARNING: Vehicle apogee exceeds %.03f meters!", simState->altitude_max_a);
    }

    if (simState->velocity_max >= 343)
    {
        bprintlf(YELLOW_BG "WARNING: Vehicle maximum speed exceeds %.03f meters per second!", simState->velocity_max);
    }

    bprintlf();
}