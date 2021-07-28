/**
 * @file main.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// #include <iostream>
// #include <cstdlib>
#include "Display.hpp"
#include "Simulation.hpp"
#include "ui.hpp"

int main (int argc, char **argv)
{
    Display::introduction();
    Display::helpAbridged();

    // Simulation simulation();
    Simulation *simulation = new Simulation();

    // for (bool exit = false; !exit; exit = user_input_handler(simulation, &exit));
    user_input_handler(simulation);

    delete simulation;

    return 1;
}