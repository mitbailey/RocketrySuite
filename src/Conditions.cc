/**
 * @file Conditions.cc
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

#include "Conditions.hcc"
#include "common.hcc"

Conditions::Conditions()
{
    pressure = 101325;
    temperature = 273.15;
    windspeed = 0;
    CalculateSetAirDensity();
}

Conditions::Conditions(double temperature, double pressure)
{
    this->pressure = pressure;
    this->temperature = temperature;
    windspeed = 0;
    CalculateSetAirDensity();
}

Conditions::Conditions(double temperature, double pressure, double windspeed)
{
    this->pressure = pressure;
    this->temperature = temperature;
    this->windspeed = windspeed;
    CalculateSetAirDensity();
}

void Conditions::UpdateConditions(double temperature, double pressure)
{
    this->pressure = pressure;
    this->temperature = temperature;
    CalculateSetAirDensity();
}

void Conditions::UpdateConditions(double temperature, double pressure, double windspeed)
{
    this->pressure = pressure;
    this->temperature = temperature;
    this->windspeed = windspeed;
    CalculateSetAirDensity();
}

double Conditions::CalculateSetAirDensity()
{
    airDensity = pressure / (R * temperature);
    return airDensity;
}