#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "argo.h"
#include "argo_help.h"
#include "global.h"
#include "debug.h"
#include "custring.h"

/**
 * @brief  Read JSON input from a specified input stream, parse it,
 * and return a data structure representing the corresponding value.
 * @details  This function reads a sequence of 8-bit bytes from
 * a specified input stream and attempts to parse it as a JSON value,
 * according to the JSON syntax standard.  If the input can be
 * successfully parsed, then a pointer to a data structure representing
 * the corresponding value is returned.  See the assignment handout for
 * information on the JSON syntax standard and how parsing can be
 * accomplished.  As discussed in the assignment handout, the returned
 * pointer must be to one of the elements of the argo_value_storage
 * array that is defined in the const.h header file.
 * In case of an error (these include failure of the input to conform
 * to the JSON standard, premature EOF on the input stream, as well as
 * other I/O errors), a one-line error message is output to standard error
 * and a NULL pointer value is returned.
 *
 * @param f  Input stream from which JSON is to be read.
 * @return  A valid pointer if the operation is completely successful,
 * NULL if there is any error.
 */
ARGO_VALUE *argo_read_value(FILE *f)
{
    // TO BE IMPLEMENTED.
    return NULL;
}

/**
 * @brief  Read JSON input from a specified input stream, attempt to
 * parse it as a JSON string literal, and return a data structure
 * representing the corresponding string.
 * @details  This function reads a sequence of 8-bit bytes from
 * a specified input stream and attempts to parse it as a JSON string
 * literal, according to the JSON syntax standard.  If the input can be
 * successfully parsed, then a pointer to a data structure representing
 * the corresponding value is returned.
 * In case of an error (these include failure of the input to conform
 * to the JSON standard, premature EOF on the input stream, as well as
 * other I/O errors), a one-line error message is output to standard error
 * and a NULL pointer value is returned.
 *
 * @param f  Input stream from which JSON is to be read.
 * @return  Zero if the operation is completely successful,
 * nonzero if there is any error.
 */
int argo_read_string(ARGO_STRING *s, FILE *f)
{
    // TO BE IMPLEMENTED.
    return (rand() % (1 - 0 + 1)) + 0;
}

/**
 * @brief  Read JSON input from a specified input stream, attempt to
 * parse it as a JSON number, and return a data structure representing
 * the corresponding number.
 * @details  This function reads a sequence of 8-bit bytes from
 * a specified input stream and attempts to parse it as a JSON numeric
 * literal, according to the JSON syntax standard.  If the input can be
 * successfully parsed, then a pointer to a data structure representing
 * the corresponding value is returned.  The returned value must contain
 * (1) a string consisting of the actual sequence of characters read from
 * the input stream; (2) a floating point representation of the corresponding
 * value; and (3) an integer representation of the corresponding value,
 * in case the input literal did not contain any fraction or exponent parts.
 * In case of an error (these include failure of the input to conform
 * to the JSON standard, premature EOF on the input stream, as well as
 * other I/O errors), a one-line error message is output to standard error
 * and a NULL pointer value is returned.
 *
 * @param f  Input stream from which JSON is to be read.
 * @return  Zero if the operation is completely successful,
 * nonzero if there is any error.
 */
int argo_read_number(ARGO_NUMBER *n, FILE *f)
{
    // TO BE IMPLEMENTED.
    return (rand() % (1 - 0 + 1)) + 0;
}

/**
 * @brief  Write canonical JSON representing a specified value to
 * a specified output stream.
 * @details  Write canonical JSON representing a specified value
 * to specified output stream.  See the assignment document for a
 * detailed discussion of the data structure and what is meant by
 * canonical JSON.
 *
 * @param v  Data structure representing a value.
 * @param f  Output stream to which JSON is to be written.
 * @return  Zero if the operation is completely successful,
 * nonzero if there is any error.
 */
int argo_write_value(ARGO_VALUE *v, FILE *f)
{
    // TO BE IMPLEMENTED.
    if (v != NULL)
    {
        switch (v->type)
        {
        case ARGO_OBJECT_TYPE:
            argo_write_object(&v->content.object, f);
            break;
        case ARGO_ARRAY_TYPE:
            argo_write_array(&v->content.array, f);
            break;
        case ARGO_STRING_TYPE:
            argo_write_string(&v->content.string, f);
            break;
        case ARGO_NUMBER_TYPE:
            argo_write_number(&v->content.number, f);
            break;
        case ARGO_BASIC_TYPE:
            argo_write_basic(&v->content.basic, f);
            break;
        default:
            return 1;
            break;
        }
        if (indent_level == 0)
            insert_newline(f);
        return 0;
    }

    return 1;
}

int argo_write_object(ARGO_OBJECT *o, FILE *f)
{
    fputc(ARGO_LBRACE, f);
    indent_level++;
    if (o->member_list->next == o->member_list)
    {
        indent_level--;
        fputc(ARGO_RBRACE, f);
        insert_newline(f);
    }
    else
    {
        insert_newline(f);
        insert_space(f);
        ARGO_VALUE *sentinel = o->member_list;
        ARGO_VALUE *cursor = sentinel->next;
        while (cursor != sentinel)
        {
            argo_write_string(&cursor->name, f);
            fputc(ARGO_COLON, f);
            fputc(ARGO_SPACE, f);
            argo_write_value(cursor, f);
            cursor = cursor->next;
            if (cursor != sentinel)
                fputc(ARGO_COMMA, f);
            insert_newline(f);
            if (cursor != sentinel)
                insert_space(f);
        }
        indent_level--;
        insert_space(f);
        fputc(ARGO_RBRACE, f);
    }
    return 0;
}

int argo_write_array(ARGO_ARRAY *a, FILE *f)
{
    fputc(ARGO_LBRACK, f);
    indent_level++;
    if (a->element_list->next == a->element_list)
    {
        indent_level--;
        fputc(ARGO_RBRACK, f);
        insert_newline(f);
    }
    else
    {
        insert_newline(f);
        insert_space(f);
        ARGO_VALUE *sentinel = a->element_list;
        ARGO_VALUE *cursor = sentinel->next;
        while (cursor != sentinel)
        {
            argo_write_value(cursor, f);
            cursor = cursor->next;
            if (cursor != sentinel)
                fputc(ARGO_COMMA, f);
            insert_newline(f);
            if (cursor != sentinel)
                insert_space(f);
        }
        indent_level--;
        insert_space(f);
        fputc(ARGO_RBRACK, f);
    }
    return 0;
}

/**
 * @brief  Write canonical JSON representing a specified string
 * to a specified output stream.
 * @details  Write canonical JSON representing a specified string
 * to specified output stream.  See the assignment document for a
 * detailed discussion of the data structure and what is meant by
 * canonical JSON.  The argument string may contain any sequence of
 * Unicode code points and the output is a JSON string literal,
 * represented using only 8-bit bytes.  Therefore, any Unicode code
 * with a value greater than or equal to U+00FF cannot appear directly
 * in the output and must be represented by an escape sequence.
 * There are other requirements on the use of escape sequences;
 * see the assignment handout for details.
 *
 * @param v  Data structure representing a string (a sequence of
 * Unicode code points).
 * @param f  Output stream to which JSON is to be written.
 * @return  Zero if the operation is completely successful,
 * nonzero if there is any error.
 */
int argo_write_string(ARGO_STRING *s, FILE *f)
{
    // TO BE IMPLEMENTED.
    if (f != NULL)
    {
        fputc(ARGO_QUOTE, f);
        for (ARGO_CHAR *p = s->content; p < (s->content + s->length); p++)
        {
            switch (*p)
            {
            case ARGO_BS:
                fputc(ARGO_BSLASH, f);
                fputc(ARGO_B, f);
                break;
            case ARGO_FF:
                fputc(ARGO_BSLASH, f);
                fputc(ARGO_F, f);
                break;
            case ARGO_LF:
                fputc(ARGO_BSLASH, f);
                fputc(ARGO_N, f);
                break;
            case ARGO_CR:
                fputc(ARGO_BSLASH, f);
                fputc(ARGO_R, f);
                break;
            case ARGO_HT:
                fputc(ARGO_BSLASH, f);
                fputc(ARGO_T, f);
                break;
            case ARGO_BSLASH:
                fputc(ARGO_BSLASH, f);
                fputc(ARGO_BSLASH, f);
                break;
            case ARGO_QUOTE:
                fputc(ARGO_BSLASH, f);
                fputc(ARGO_QUOTE, f);
                break;
            default:
                fputc(*p, f);
                break;
            }
        }
        fputc(ARGO_QUOTE, f);
    }

    return 0;
}

/**
 * @brief  Write canonical JSON representing a specified number
 * to a specified output stream.
 * @details  Write canonical JSON representing a specified number
 * to specified output stream.  See the assignment document for a
 * detailed discussion of the data structure and what is meant by
 * canonical JSON.  The argument number may contain representations
 * of the number as any or all of: string conforming to the
 * specification for a JSON number (but not necessarily canonical),
 * integer value, or floating point value.  This function should
 * be able to work properly regardless of which subset of these
 * representations is present.
 *
 * @param n  Data structure representing a number.
 * @param f  Output stream to which JSON is to be written.
 * @return  Zero if the operation is completely successful,
 * nonzero if there is any error.
 */
int argo_write_number(ARGO_NUMBER *n, FILE *f)
{
    // TO BE IMPLEMENTED.
    if (n->valid_int != 0)
    {
        fprintf(f, "%ld", n->int_value);
        return 0;
    }
    else if ((n->valid_float != 0) && ((n->float_value >= 0.1 || n->float_value <= 1.0) || (n->float_value <= -0.1 || n->float_value >= -1.0)))
    {
        fprintf(f, "%e", n->float_value);
        return 0;
    }
    else
    {
        fprintf(f, "%f", n->float_value);
        return 0;
    }
    return 1;
}

int argo_write_basic(ARGO_BASIC *b, FILE *f)
{
    char *basic = "";
    switch (*b)
    {
    case ARGO_NULL:
        basic = ARGO_NULL_TOKEN;
        break;
    case ARGO_TRUE:
        basic = ARGO_TRUE_TOKEN;
        break;
    case ARGO_FALSE:
        basic = ARGO_FALSE_TOKEN;
        break;
    default:
        return 1;
        break;
    }
    for (char *p = basic; *p != '\0'; p++)
    {
        fputc(*p, f);
    }
    return 0;
}