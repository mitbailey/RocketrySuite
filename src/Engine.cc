/**
 * @file Engine.cc
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

void Engine::Print()
{
    bprintlf("Mass empty:  %.03f", massEmpty);
    bprintlf("Mass loaded: %.03f", massLoaded);
    bprintlf("Impulse:     %.03f", impulse);
    bprintlf("Burn time:   %.03f", burnTime);
}