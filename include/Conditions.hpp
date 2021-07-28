/**
 * @file Conditions.hpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CONDITIONS_HPP
#define CONDITIONS_HPP

class Conditions
{
public:
    Conditions();
    Conditions(double temperature, double pressure);
    Conditions(double temperature, double pressure, double windspeed);

    void updateConditions(double temperature, double pressure);
    void updateConditions(double temperature, double pressure, double windspeed);

    double pressure;    // Pascals
    double temperature; // Kelvin
    double windspeed;   // m/s
    double air_density; // kg/m^3

private:
    double calculateAirDensity();
};

#endif // CONDITIONS_HPP