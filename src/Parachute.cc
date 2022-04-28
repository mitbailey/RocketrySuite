/**
 * @file Parachute.cc
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

#include "meb_print.h"
#include "Parachute.hcc"
#include "Vehicle.hcc"
#include "math.h"
#include "common.hcc"

// Parachute::Parachute(double diameter, double drag_coefficient)
// {
//     this->diameter = diameter;
//     this->dragCoefficient = drag_coefficient;
// }

Parachute::Parachute()
{
    this->diameter = 0;
    this->dragCoefficient = 0;
}

/**
 * @brief 
 * 
 * Either diameter or landingVelocity can be set, the other must be calculated.
 * 
 * @param diameter 
 * @param landingVelocity
 * @param dragCoefficient 
 * @param deploymentTime Seconds after launch the parachute will deploy. Usually, this is determined by the estes engine. 
 */
void Parachute::UpdateParachute(double diameter, double landingVelocity, double dragCoefficient, double deploymentTime)
{
    if (diameter > 0 && landingVelocity > 0)
    {
        bprintlf(RED_FG "ERROR: Cannot directly set both diameter and landing velocity.");
        return;
    }
    else if (diameter > 0)
    { 
        this->diameter = diameter;
    }
    else
    {
        this->landingVelocity = landingVelocity;
    }

    this->dragCoefficient = dragCoefficient;
    this->deploymentTime = deploymentTime;
}

void Parachute::displayParachute()
{
    bprintlf("Diameter: %.02f", diameter);
    bprintlf("Drag Coefficient: %.02f", dragCoefficient);
    bprintlf("Landing Velocity: %.02f", landingVelocity);
    bprintlf("Time to Deploy: %.02f", deploymentTime);
}

// Calculates the diameter required to achieve the desired descent speed.
double Parachute::CalculateSetDiameter(double vehicle_mass_at_descent, double air_density)
{
    diameter = sqrt((8 * vehicle_mass_at_descent * g) / (M_PI * air_density * dragCoefficient * (landingVelocity * landingVelocity)));
    return diameter;
};

// Calculates the speed from the diameter and mass.
double Parachute::CalculateSetDescentSpeed(double vehicle_mass_at_descent, double air_density)
{
    landingVelocity = sqrt((8 * vehicle_mass_at_descent * g) / (M_PI * air_density * dragCoefficient * (diameter * diameter)));
    return landingVelocity;
};

void Parachute::Print()
{
    bprintlf("PARACHUTE~");
    bprintlf("Diameter:         %.03f m", diameter);
    bprintlf("Drag coefficient: %.03f", dragCoefficient);
}