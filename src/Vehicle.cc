/**
 * @file Vehicle.cc
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief
 * @version See Git tags for version information.
 * @date 2022.04.23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Vehicle.hcc"

Vehicle::Vehicle(double mass_empty, double cross_sectional_area, double drag_coefficient)
{
    this->massEmpty = mass_empty;
    // this->massLoaded = mass_loaded;
    this->crossSectionalArea = cross_sectional_area;
    this->dragCoefficient = drag_coefficient;
}

void Vehicle::UpdateVehicle(double mass_empty, double cross_sectional_area, double drag_coefficient)
{
    this->massEmpty = mass_empty;
    // this->massLoaded = mass_loaded;
    this->crossSectionalArea = cross_sectional_area;
    this->dragCoefficient = drag_coefficient;
}