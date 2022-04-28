/**
 * @file input_output.cc
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief
 * @version See Git tags for version information.
 * @date 2022.04.22
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

#include "common.hcc"
#include "input_output.hcc"
#include "meb_print.h"
#include "stdint.h"
#include "stdlib.h"

void introduction()
{
    bprintlf("--- MODEL ROCKETRY CALCULATION SUITE v%s ---", _VER_);

    bprintlf("\nCopyright (C) 2022  Mit Bailey");
    bprintlf("This program comes with ABSOLUTELY NO WARRANTY.");
    bprintlf("This is free software, and you are welcome to redistribute it under certain conditions. Type `license' to view licensing information.\n");

    bprintlf("github.com/mitbailey\n");
}

void display_help_abridged()
{
    bprintlf("To view help, type help.");
    bprintlf("To view command-specific help, type help <command>.\n");
}

void display_help_verbose()
{
    bprintlf(">help - Display available commands and what they do.");
    bprintlf(">help units - Display required units.");
    bprintlf(">help <command> - Display detailed information about that command.\n");

    bprintlf(">run - Run the simulation given the current launch vehicle configuration and weather conditions.");
    bprintlf(">set vehicle - Creates a new launch vehicle with the relevant parameters.");
    bprintlf(">set conditions - Creates a new set of weather conditions.");
    bprintlf(">set parachute - Sets the parameters of the vehicle's parachute.");
    bprintlf(">set angle - Manually sets the launch angle of the vehicle.");
    bprintlf(">display vehicle - Displays the current launch vehicle.");
    bprintlf(">display conditions - Displays the current weather conditions.");
    bprintlf(">display parachute - Displays the current parachute configuration.");
    bprintlf(">display angle - Displays the current launch angle.");
    bprintlf(">calculate parachute diameter - Uses the current parachute configuration to determine optimal diameter.");
    bprintlf(">calculate parachute velocity - Uses the current parachute configuration to determine landing velocity.");
    bprintlf(">calculate angle - Sets the launch angle to what will return the rocket to the launchsite.");
    bprintlf(">calculate area - Displays the area of a circle with the given diameter.");
    bprintlf(">update - Can be used to change a single value of a class.\n");

    bprintlf(">credits - Shows the credits for the program.");
    bprintlf(">exit - Closes the program.\n");
}

void display_help_command(const char *command)
{
    if (!strcmp(command, "help"))
    {
        bprintlf("Description: ");
        bprintlf("Displays all commands with a short description of what they do.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... N/A");
        bprintlf("Optional... <units>, <command> \n");
    }
    else if (!strcmp(command, "<command>"))
    {
        bprintlf("Try it without the <> and with a command name instead.\n");
    }
    else if (!strcmp(command, "credits"))
    {
        bprintlf("Description: ");
        bprintlf("Shows the credits for the program.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... N/A");
        bprintlf("Optional... N/A\n");
    }
    else if (!strcmp(command, "units"))
    {
        bprintlf("Mass -------- Kilograms");
        bprintlf("Length ------ Meters");
        bprintlf("Distance ---- Meters");
        bprintlf("Velocity ---- Meters per Second");
        bprintlf("Pressure ---- Pascals");
        bprintlf("Temperature - Kelvin");
        bprintlf("Area -------- Square Meters");
        bprintlf("Impulse ----- Newton-Seconds");
        bprintlf("Thrust ------ Newtons");
        bprintlf("Time -------- Seconds\n");
    }
    else if (!strcmp(command, "set vehicle"))
    {
        bprintlf("Description: ");
        bprintlf("Creates a new launch vehicle with the relevant parameters.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... <Vehicle Mass (Empty)> <Propellant Mass> <Engine Mass (Loaded)> <Cross-Sectional Area> <Engine Impulse> <Engine Thrust>");
        bprintlf("Optional... <Coefficient of Drag>, <Angle>\n");
    }
    else if (!strcmp(command, "set conditions"))
    {
        bprintlf("Description: ");
        bprintlf("Creates a new set of weather conditions.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... <Temperature> <Pressure>");
        bprintlf("Optional... <Windspeed>\n");
    }
    else if (!strcmp(command, "set parachute"))
    {
        bprintlf("Description: ");
        bprintlf("Sets the parameters of the vehicle's parachute.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... <Diameter> <Coefficient of Drag> <Desired Landing Velocity> <Deployment Time>");
        bprintlf("Optional... N/A");
        bprintlf("Notes...    To omit one or more arguments, enter a negative value for that argument.\n");
    }
    else if (!strcmp(command, "set angle"))
    {
        bprintlf("Description: ");
        bprintlf("Sets the launch angle of the vehicle.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... <Launch Angle>");
        bprintlf("Optional... N/A");
        bprintlf("Notes...    Angle is only used in range and drift calculations.\n");
    }
    else if (!strcmp(command, "display vehicle"))
    {
        bprintlf("Description: ");
        bprintlf("Displays the current launch vehicle.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... N/A");
        bprintlf("Optional... N/A\n");
    }
    else if (!strcmp(command, "display conditions"))
    {
        bprintlf("Description: ");
        bprintlf("Displays the current weather conditions.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... N/A");
        bprintlf("Optional... N/A\n");
    }
    else if (!strcmp(command, "display parachute"))
    {
        bprintlf("Description: ");
        bprintlf("Displays the current parachute configuration.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... N/A");
        bprintlf("Optional... N/A\n");
    }
    else if (!strcmp(command, "display angle"))
    {
        bprintlf("Description: ");
        bprintlf("Displays the current launch angle.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... N/A");
        bprintlf("Optional... N/A\n");
    }
    else if (!strcmp(command, "calculate angle"))
    {
        bprintlf("Description: ");
        bprintlf("Sets the launch angle to what will return the rocket to the launchsite.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... N/A");
        bprintlf("Optional... N/A\n");
    }
    else if (!strcmp(command, "calculate area"))
    {
        bprintlf("Description: ");
        bprintlf("Displays the area of a circle with the given diameter.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... <Diameter>");
        bprintlf("Optional... N/A\n");
    }
    else if (!strcmp(command, "calculate parachute diameter"))
    {
        bprintlf("Description: ");
        bprintlf("Uses the current parachute configuration to determine optimal diameter.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... N/A");
        bprintlf("Optional... N/A\n");
    }
    else if (!strcmp(command, "calculate parachute velocity"))
    {
        bprintlf("Description: ");
        bprintlf("Uses the current parachute configuration to determine landing velocity.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... N/A");
        bprintlf("Optional... N/A\n");
    } // .update - Can be used to change a single value of a class.
    else if (!strcmp(command, "update"))
    {
        bprintlf("Description: ");
        bprintlf("Can be used to change a single value of a class.\n");

        bprintlf("Parameters: ");
        bprintlf("	conditions");
        bprintlf("		<temperature> <pressure> <windspeed>");
        bprintlf("		temperature <value>");
        bprintlf("		pressure <value>");
        bprintlf("		windspeed <value>");
        bprintlf("	parachute");
        bprintlf("		<diameter> <dragCoefficient> <landingVelocity> <deploymentTime>");
        bprintlf("		diameter <value>");
        bprintlf("		dragCoefficient <value>");
        bprintlf("		landingVelocity <value>");
        bprintlf("		deploymentTime <value>");
        bprintlf("	engine");
        bprintlf("		<impulse> <thrust> <burntime> <loaded mass> <propellant mass>");
        bprintlf("		impulse <value>");
        bprintlf("		thrust <value>");
        bprintlf("		burntime <value>");
        bprintlf("		mass");
        bprintlf("			loaded <value>");
        bprintlf("			propellant <value>");
        bprintlf("	vehicle");
        bprintlf("		area <value>");
        bprintlf("		dragCoefficient <value>");
        bprintlf("		mass");
        bprintlf("			loaded <value>");
        bprintlf("			empty <value>\n");

        bprintlf("Examples:");
        bprintlf(".update engine mass loaded 2.5");
        bprintlf(".update conditions 275 101256");
        bprintlf(".update conditions temperature 275\n");
    }
    else if (!strcmp(command, "exit"))
    {
        bprintlf("Description: ");
        bprintlf("Closes the program.\n");

        bprintlf("Parameters: ");
        bprintlf("Required... N/A");
        bprintlf("Optional... N/A\n");
    }
}

void display_credits()
{
    // TODO: Make credits printout.
}

void display_license()
{
    bprintlf("Model Rocketry Calculation Suite - Program to calculate the trajectory of a model rocket.");
    bprintlf("Copyright (C) 2022  Mit Bailey\n");
    
    bprintlf("This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\n");
    
    bprintlf("This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.\n");
    
    bprintlf("You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.\n");
}

void tokenize(const char *input, char tokens[TOKENS_LEN_X][TOKENS_LEN_Y], uint16_t tokens_len_x, uint16_t tokens_len_y)
{
    // NOTE: arr[a][b] == arr[(a * a_len) + (b)]

    // Tokenize the input.
    for (size_t i = 0, x = 0, y = 0; i < strlen(input); i++, y++)
    {
        if (input[i] == ' ')
        {
            tokens[x][y] = '\0';
            x++;
            y = -1;
        }
        else
        {
            tokens[x][y] = input[i];
        }
    }

    // TODO: Remove debug printouts.
    // Debug print-out for the tokenized input.
    for (int i = 0; i < 32; i++)
    {
        if (tokens[i][0] == '\0')
        {
            break;
        }
        dbprintlf("Token: %s", tokens[i]);
    }
}

void parse_and_execute(Simulation *sim, const char tokens[TOKENS_LEN_X][TOKENS_LEN_Y], uint16_t tokens_len_x, uint16_t tokens_len_y)
{
    // Parse the input.
    if (!strcmp(tokens[0], "help"))
    {
        dbprintlf("Entered help section.");

        if (tokens[1][0] == '\0')
        { // Only one token.
            display_help_verbose();
        }
        else
        {
            // Wraps all but the 'help' into a string and sends to display_help_command as one 'command'.
            char command[TOKENS_LEN_X * TOKENS_LEN_Y] = {0};
            strcpy(command, tokens[1]);
            for (int i = 2; (i < TOKENS_LEN_X) && (tokens[i][0] != NULL); i++)
            {
                strcat(command, " ");
                strcat(command, tokens[i]);
                dbprintlf("-->> %s", tokens[i]);
            }

            display_help_command(command);
        }
    }
    else if (!strcmp(tokens[0], "license"))
    {
        display_license();
    }
    else if (!strcmp(tokens[0], "run"))
    {
        // simulation->run();
        sim->Simulate();
    }
    else if (!strcmp(tokens[0], "set"))
    {
        if (!strcmp(tokens[1], "vehicle"))
        {
        }
        else if (!strcmp(tokens[1], "conditions"))
        {
        }
        else if (!strcmp(tokens[1], "parachute"))
        {
        }
        else if (!strcmp(tokens[1], "angle"))
        {
        }
    }
    else if (!strcmp(tokens[0], "display"))
    {
        if (!strcmp(tokens[1], "vehicle"))
        {
        }
        else if (!strcmp(tokens[1], "conditions"))
        {
        }
        else if (!strcmp(tokens[1], "parachute"))
        {
        }
        else if (!strcmp(tokens[1], "angle"))
        {
        }
    }
    else if (!strcmp(tokens[0], "calculate"))
    {
        if (!strcmp(tokens[1], "parachute"))
        {
            if (!strcmp(tokens[1], "diameter"))
            {
            }
            else if (!strcmp(tokens[1], "velocity"))
            {
            }
        }
        else if (!strcmp(tokens[1], "angle"))
        {
        }
        else if (!strcmp(tokens[1], "area"))
        {
        }
    }
    else if (!strcmp(tokens[0], "credits"))
    {
    }
    else if (!strcmp(tokens[0], "exit"))
    {
        exit(0);
    }
    else
    {
        bprintlf(RED_FG "ERROR: Unknown command '%s'.", tokens[0]);
    }
}