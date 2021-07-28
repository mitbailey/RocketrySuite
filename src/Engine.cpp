/**
 * @file Engine.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Engine.hpp"

Engine::Engine(double mass_empty, double mass_loaded, double impulse, double burn_time)
{
    this->mass_empty = mass_empty;
    this->mass_loaded = mass_loaded;
    this->impulse = impulse;
    this->burn_time = burn_time;
}

double Engine::calculateAverageThrust()
{
    thrust = impulse / burn_time;
    return thrust;
}