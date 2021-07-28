/**
 * @file Display.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "Display.hpp"

void Display::introduction()
{
	std::cout << "--- MODEL ROCKETRY CALCULATION SUITE V2 ---" << std::endl;
	std::cout << "Copyright Mit Bailey 2020" << std::endl;
	std::cout << "mitbailey.com" << std::endl;
	std::cout << std::endl;
}

void Display::help()
{
	std::cout << ">help - Display available commands and what they do." << std::endl;
	std::cout << ">help units - Display required units." << std::endl;
	std::cout << ">help <command> - Display detailed information about that command." << std::endl;
	std::cout << std::endl;

	std::cout << ">run - Run the simulation given the current launch vehicle configuration and weather conditions." << std::endl;
	std::cout << ">set vehicle - Creates a new launch vehicle with the relevant parameters." << std::endl;
	std::cout << ">set conditions - Creates a new set of weather conditions." << std::endl;
	std::cout << ">set parachute - Sets the parameters of the vehicle's parachute." << std::endl;
	std::cout << ">set angle - Manually sets the launch angle of the vehicle." << std::endl;
	std::cout << ">display vehicle - Displays the current launch vehicle." << std::endl;
	std::cout << ">display conditions - Displays the current weather conditions." << std::endl;
	std::cout << ">display parachute - Displays the current parachute configuration." << std::endl;	
	std::cout << ">display angle - Displays the current launch angle." << std::endl;
	std::cout << ">calculate parachute diameter - Uses the current parachute configuration to determine optimal diameter." << std::endl;
	std::cout << ">calculate parachute velocity - Uses the current parachute configuration to determine landing velocity." << std::endl;
	std::cout << ">calculate angle - Sets the launch angle to what will return the rocket to the launchsite." << std::endl;
	std::cout << ">calculate area - Displays the area of a circle with the given diameter." << std::endl;
	std::cout << ">update - Can be used to change a single value of a class." << std::endl;
	std::cout << std::endl;

	std::cout << ">credits - Shows the credits for the program." << std::endl;
	std::cout << ">exit - Closes the program." << std::endl;
	std::cout << std::endl;
}

void Display::helpAbridged()
{
	std::cout << "To view help, type help" << std::endl;
	std::cout << "To view command-specific help, type help <command>" << std::endl;
	std::cout << std::endl;
}