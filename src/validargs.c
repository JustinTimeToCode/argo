#include <stdlib.h>

#include "argo.h"
#include "global.h"
#include "debug.h"
#include "custring.h"

/**
 * @brief Validates command line arguments passed to the program.
 * @details This function will validate all the arguments passed to the
 * program, returning 0 if validation succeeds and -1 if validation fails.
 * Upon successful return, the various options that were specified will be
 * encoded in the global variable 'global_options', where it will be
 * accessible elsewhere in the program.  For details of the required
 * encoding, see the assignment handout.
 *
 * @param argc The number of arguments passed to the program from the CLI.
 * @param argv The argument strings passed to the program from the CLI.
 * @return 0 if validation succeeds and -1 if validation fails.
 * @modifies global variable "global_options" to contain an encoded representation
 * of the selected program options.
 */

int validargs(int argc, char **argv)
{
    // TO BE IMPLEMENTED
    if (argc <= 1)
    {
        return -1;
    }

    int h_idx = str_indexOf("-h", argv, argc);
    if (h_idx == 1)
    {
        global_options = HELP_OPTION;
        return 0;
    }
    int c_idx = str_indexOf("-c", argv, argc);
    int v_idx = str_indexOf("-v", argv, argc);
    int p_idx = str_indexOf("-p", argv, argc);
    int INDENT = (p_idx != -1 && p_idx < argc - 1) ? str_to_int(*(argv + p_idx + 1)) : 4;
    if (c_idx == 1)
    {
        global_options = CANONICALIZE_OPTION;
        if (p_idx != -1 && p_idx == c_idx + 1)
        {
            global_options |= PRETTY_PRINT_OPTION | INDENT;
        }
        return 0;
    }
    else if (v_idx == 1 && v_idx == argc - 1)
    {
        global_options = VALIDATE_OPTION;
        return 0;
    }
    else
    {
        return -1;
    }
    // abort();
    return -1;
}