/**
 * @file main.cc
 * @author Mit Bailey (mitbailey99@gmail.com)
 * @brief
 * @version See Git tags for version information.
 * @date 2022.04.22
 *
 * This program is CC21 compliant (https://github.com/SmallSatMakers/CC21).
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdint.h>
#include <string.h>
#include "meb_print.h"
#include "input_output.hcc"
#include "common.hcc"
#include "Simulation.hcc"

int main(int argc, char **argv)
{
    introduction();
    display_help_abridged();

    char tokens[TOKENS_LEN_X][TOKENS_LEN_Y] = {0};
    char input[TOKENS_LEN_X * TOKENS_LEN_Y] = {0};

    Simulation *sim = new Simulation();

    uint8_t done = 0;
    while (!done)
    {
        memset(tokens, '\0', sizeof(tokens));
        memset(input, 0x0, sizeof(input));

        bprintf(">");

        // Get a line of user input.
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

        // Print newline.
        bprintlf();

        // Tokenize the input.
        uint16_t num_tokens = tokenize(input, tokens, TOKENS_LEN_X, TOKENS_LEN_Y);

        // Parse the input.
        parse_and_execute(sim, tokens, num_tokens);
    }

    delete sim;

    return 0;
}