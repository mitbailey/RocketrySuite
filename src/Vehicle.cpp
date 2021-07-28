/**
 * @file Vehicle.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Vehicle.hpp"

Vehicle::Vehicle(double mass_empty, double mass_loaded, double cross_sectional_area, double drag_coefficient)
{
    this->mass_empty = mass_empty;
    this->mass_loaded = mass_loaded;  
    this->cross_sectional_area = cross_sectional_area;  
    this->drag_coefficient = drag_coefficient;
}

void Vehicle::updateVehicle(double mass_empty, double mass_loaded, double cross_sectional_area, double drag_coefficient)
{
    this->mass_empty = mass_empty;
    this->mass_loaded = mass_loaded;  
    this->cross_sectional_area = cross_sectional_area;  
    this->drag_coefficient = drag_coefficient;
}