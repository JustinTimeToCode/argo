#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "argo.h"

/**
 * @brief Checks to see if the pretty print option has been enabled
 *
 * @return true if it has been
 * @return false if it isn't
 */
bool is_pretty_print_enabled();

/**
 * @brief Conditionally inserts a space into the FILE stream
 *
 * @param f FILE stream
 */
void insert_space(FILE *f);

/**
 * @brief Conditionally insert a newline into the FILE stream
 *
 * @param f FILE stream
 */
void insert_newline(FILE *f);

/**
 * @brief Get the indent value from the encoded "global options variable"
 *
 * @return int the number of spaces to indent (base multiplier)
 */
int get_indent(void);

/**
 * @brief  Write canonical JSON representing a specified boolean or null value to
 * a specified output stream.
 * @details  Write canonical JSON representing a specified boolean or null value
 * to specified output stream. See the assignment document for a
 * detailed discussion of the data structure and what is meant by
 * canonical JSON.
 *
 * @param v  Data structure representing a value.
 * @param f  Output stream to which JSON is to be written.
 * @return  Zero if the operation is completely successful,
 * nonzero if there is any error.
 */
int argo_write_basic(ARGO_BASIC *b, FILE *f);

/**
 * @brief  Write canonical JSON representing a specified object value to
 * a specified output stream.
 * @details  Write canonical JSON representing a specified onject value
 * to specified output stream.  See the assignment document for a
 * detailed discussion of the data structure and what is meant by
 * canonical JSON.
 *
 * @param v  Data structure representing a value.
 * @param f  Output stream to which JSON is to be written.
 * @return  Zero if the operation is completely successful,
 * nonzero if there is any error.
 */
int argo_write_object(ARGO_OBJECT *o, FILE *f);

/**
 * @brief  Write canonical JSON representing a specified array value to
 * a specified output stream.
 * @details  Write canonical JSON representing a specified array value
 * to specified output stream.  See the assignment document for a
 * detailed discussion of the data structure and what is meant by
 * canonical JSON.
 *
 * @param v  Data structure representing a value.
 * @param f  Output stream to which JSON is to be written.
 * @return  Zero if the operation is completely successful,
 * nonzero if there is any error.
 */
int argo_write_array(ARGO_ARRAY *a, FILE *f);
