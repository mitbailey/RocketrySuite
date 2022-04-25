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
#include "meb_print.h"

Conditions::Conditions()
{
    pressure = 101325;
    temperature = 273.15;
    windspeed = 0;
    CalculateSetAirDensity();
}

void Conditions::UpdateConditions(double windspeed)
{
    this->windspeed = windspeed;
}

void Conditions::UpdateConditions(double windspeed, double temperature)
{
    this->windspeed = windspeed;
    this->temperature = temperature;
    CalculateSetAirDensity();
}

void Conditions::UpdateConditions(double windspeed, double temperature, double pressure)
{
    this->pressure = pressure;
    this->temperature = temperature;
    this->windspeed = windspeed;
    CalculateSetAirDensity();
}

void Conditions::Print()
{
    bprintlf("CONDITIONS~");
    bprintlf("Temperature: %.03f", temperature);
    bprintlf("Pressure:    %.03f", pressure);
    bprintlf("Air density: %.03f", airDensity);
    bprintlf("Windspeed:   %.03f", windspeed);
}

double Conditions::CalculateSetAirDensity()
{
    airDensity = pressure / (R * temperature);
    return airDensity;
}