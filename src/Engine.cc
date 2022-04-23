/**
 * @file Engine.cc
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief
 * @version See Git tags for version information.
 * @date 2022.04.23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Engine.hcc"

Engine::Engine(double mass_empty, double mass_loaded, double impulse, double burn_time)
{
    this->massEmpty = mass_empty;
    this->massLoaded = mass_loaded;
    this->impulse = impulse;
    this->burnTime = burn_time;
}

double Engine::CalculateAverageThrust()
{
    thrust = impulse / burnTime;
    return thrust;
}