/**
 * @file Conditions.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Conditions.hpp"
#include "constants.h"

Conditions::Conditions()
{
    pressure = 101325;
    temperature = 273.15;
    windspeed = 0;
    calculateAirDensity();
}

Conditions::Conditions(double temperature, double pressure)
{
    this->pressure = pressure;
    this->temperature = temperature;
    windspeed = 0;
    calculateAirDensity();
}

Conditions::Conditions(double temperature, double pressure, double windspeed)
{
    this->pressure = pressure;
    this->temperature = temperature;
    this->windspeed = windspeed;
    calculateAirDensity();
}

void Conditions::updateConditions(double temperature, double pressure)
{
    this->pressure = pressure;
    this->temperature = temperature;
    calculateAirDensity();    
}

void Conditions::updateConditions(double temperature, double pressure, double windspeed)
{
    this->pressure = pressure;
    this->temperature = temperature;
    this->windspeed = windspeed;
    calculateAirDensity();
}

double Conditions::calculateAirDensity()
{
    air_density = pressure / (R * temperature);
    return air_density;
}