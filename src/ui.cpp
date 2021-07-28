/**
 * @file ui.cpp
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021.07.28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <string.h>
#include "ui.hpp"
#include "Display.hpp"

void user_input_handler(Simulation *simulation)
{
    // Maximum of 32 arguments, each a maximum of 64 characters long.
    char tokens[32][64];
    char input[2048];

    bool exit = false;
    while (!exit)
    {
        memset(tokens, '\0', 32 * 64);
        memset(input, 0x0, 2048);

        printf(">");

        // Get line of user input.
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            // No input.
            continue;
        }

        if (input[strlen(input) - 1] != '\n')
        {
            // Input too large, flush the buffer.
            int retval = 0;
            while ((retval = getchar()) != '\n' && retval != EOF)
                ;
            continue;
        }

        // Input was not erroneous. Replace newline with null-terminator.
        input[strlen(input) - 1] = '\0';

        // 01234567 i
        // abcd efg raw_input
        // 00000111 tokenized_input[]
        // 01234012 tokenized_input  []

        // Tokenize the input.
        for (size_t i = 0, arg = 0, ch = 0; i < strlen(input); i++, ch++)
        {
            if (input[i] == ' ')
            {
                tokens[arg][ch] = '\0';
                arg++;
                ch = -1;
            }
            else
            {
                tokens[arg][ch] = input[i];
            }
        }

        // Debug print-out for the tokenized input.
        for (int i = 0; i < 32; i++)
        {
            if (tokens[i][0] == '\0')
            {
                break;
            }
            printf("Token: %s\n", tokens[i]);
        }

        // Parse the input.
        if (strcmp(tokens[0], "help"))
        {
            if (tokens[1][0] == '\0')
            { // Only one token.
                Display::help();
            }

            if (strcmp(tokens[1], "units"))
            {
            }
            else if (strcmp(tokens[1], "run"))
            {
            }
            else if (strcmp(tokens[1], "set"))
            {
            }
            else if (strcmp(tokens[1], "display"))
            {
            }
            else if (strcmp(tokens[1], "calculate"))
            {
            }
            else if (strcmp(tokens[1], "credits"))
            {
            }
            else if (strcmp(tokens[1], "exit"))
            {
            }
        }
        else if (strcmp(tokens[0], "run"))
        {
            simulation->run();
        }
        else if (strcmp(tokens[0], "set"))
        {
        }
        else if (strcmp(tokens[0], "display"))
        {
        }
        else if (strcmp(tokens[0], "calculate"))
        {
        }
        else if (strcmp(tokens[0], "credits"))
        {
        }
        else if (strcmp(tokens[0], "exit"))
        {
        }
        else
        {
            printf("ERROR: Unknown command '%s'.\n", tokens[0]);
        }
    }
}