/**
 * @file Parachute.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Parachute.hpp"

Parachute::Parachute(double diameter, double drag_coefficient)
{
    this->diameter = diameter;
    this->drag_coefficient = drag_coefficient;
}