/**
 * @file Engine.hpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ENGINE_HPP
#define ENGINE_HPP

class Engine
{
public:
    Engine(double mass_empty, double mass_loaded, double impulse, double burn_time);

    double calculateAverageThrust();

    double mass_empty;
    double mass_loaded;
    double impulse;
    double burn_time;

private:
    double thrust;
};

#endif // ENGINE_HPP