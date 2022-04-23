/**
 * @file Conditions.cc
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief
 * @version See Git tags for version information.
 * @date 2022.04.23
 *
 * @copyright Copyright (c) 2022
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