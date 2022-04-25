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
#include "meb_print.h"

Engine::Engine()
{
    this->massEmpty = 0;
    this->massLoaded = 0;
    this->impulse = 0;
    this->burnTime = 0;
}

void Engine::UpdateEngine(double mass_empty, double mass_loaded, double impulse, double burn_time)
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

void Print()
{
    bprintlf("Mass empty:  %.03f", mass_empty);
    bprintlf("Mass loaded: %.03f", mass_loaded);
    bprintlf("Impulse:     %.03f", impulse);
    bprintlf("Burn time:   %.03f", burn_time);
}