/**
 * @file Simulation.hpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <cstdlib>
#include <list>
#include "Parachute.hpp"
#include "Engine.hpp"
#include "Vehicle.hpp"

class Simulation
{
public:
    // Simulation();

    void run();

    std::list<Parachute> parachute_list;
    std::list<Engine> engine_list;
    std::list<Vehicle> vehicle_list;
};

#endif // SIMULATION_HPP