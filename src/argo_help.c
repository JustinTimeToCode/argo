#ifndef ARGO_HELP_H
#define ARGO_HELP_H

#include <stdlib.h>
#include <stdio.h>
#include "argo_help.h"
#include "argo.h"
#include "global.h"
#include "custring.h"

/**
 * @brief Checks to see if the pretty print option has been enabled
 *
 * @return true if it has been
 * @return false if it isn't
 */
bool is_pretty_print_enabled()
{
    return (bool)(global_options & (1 << 28));
}

/**
 * @brief Get the indent value from the encoded "global options variable"
 *
 * @return int the number of spaces to indent (base multiplier)
 */
int get_indent()
{
    return global_options & 0x0000000F;
}

/**
 * @brief Conditionally inserts a space into the FILE stream
 *
 * @param f FILE stream
 */
void insert_space(FILE *f)
{
    int INDENT = get_indent();
    int total = INDENT * indent_level;
    if (is_pretty_print_enabled())
    {
        for (int i = 0; i < total; i++)
        {
            fputc(ARGO_SPACE, f);
        }
    }
}

/**
 * @brief Conditionally insert a newline into the FILE stream
 *
 * @param f FILE stream
 */
void insert_newline(FILE *f)
{
    if (is_pretty_print_enabled())
        fputc(ARGO_LF, f);
}

#endif