/**
 * @file Vehicle.hpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "Parachute.hpp"
#include "Engine.hpp"

class Vehicle
{
public:
    Vehicle(double mass_empty, double mass_loaded, double cross_sectional_area, double drag_coefficient);

    void mountEngine(Engine *engine) { this->engine = engine; };
    void mountParachute(Parachute *parachute) { this->parachute = parachute; };

    void updateVehicle(double mass_empty, double mass_loaded, double cross_sectional_area, double drag_coefficient);
    
    double mass_loaded;
    double mass_empty;
    double cross_sectional_area;
    double drag_coefficient;

    Engine *engine;
    Parachute *parachute;
};

#endif // VEHICLE_HPP