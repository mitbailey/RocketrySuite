/**
 * @file Parachute.hpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PARACHUTE_HPP
#define PARACHUTE_HPP

class Parachute
{
public:
    Parachute(double diameter, double drag_coefficient);

    double diameter;
    double drag_coefficient;
};

#endif // PARACHUTE_HPP