/**
 * @file Parachute.cc
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief
 * @version See Git tags for version information.
 * @date 2022.04.23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "meb_print.h"
#include "Parachute.hcc"
#include "Vehicle.hcc"
#include "math.h"
#include "common.hcc"

Parachute::Parachute(double diameter, double drag_coefficient)
{
    this->diameter = diameter;
    this->dragCoefficient = drag_coefficient;
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