#include <stdio.h>
#include <stdbool.h>
#include "custring.h"

/**
 * @brief My custom implementation of strlen
 *
 * @param str the string to be traversed
 * @return int the length of the string, -1 if error
 */
int lenstr(char *str)
{
    int count = 0;
    char *ptr = str;
    while (*ptr != '\0')
    {
        count++;
        ptr++;
    }
    return count;
}

/**
 * @brief My custom implementation of strcmp
 *
 * @param s1 the first string to be compared
 * @param s2 the second string to be compared
 * @return true if the strings are a match
 * @return false if the strings don't match
 */
bool str_eq(char *s1, char *s2)
{
    if (lenstr(s1) != lenstr(s2))
        return false;
    char *s1_ptr = s1;
    char *s2_ptr = s2;
    while (*s1_ptr != '\0')
    {
        if (*s1_ptr != *s2_ptr)
            return false;
        s1_ptr++;
        s2_ptr++;
    }
    return true;
}

/**
 * @brief Checks to see if an array of strings contains a certain string
 *
 * @param target the target string we are searching for
 * @param arr the array of strings (most likely argv)
 * @param arr_len the length of the array
 * @return true if the string exists within the array
 * @return false if the string cannot be found
 */
bool has_str(char *target, char *arr[], int arr_len)
{
    for (char **p = arr; p != (arr + arr_len); p++)
    {
        if (str_eq(*p, target))
            return true;
    }
    return false;
}

/**
 * @brief finds the index of the first occurrence of a target string
 *
 * @param target the search string target
 * @param arr the array of strings to traverse
 * @param arr_len the length of the array
 * @return int the index of the string or -1 if not found
 */
int str_indexOf(char *target, char *arr[], int arr_len)
{
    int i = 0;
    for (char **p = arr; p != (arr + arr_len); p++)
    {
        if (str_eq(*p, target))
            return i;
        i++;
    }
    return -1;
}

/**
 * @brief My custom implementation of atoi
 *
 * @param str the numeric string to convert to an integer
 * @return int the numeric representation of the string
 */
int str_to_int(char *str)
{
    int num = 0;
    int is_neg = 1;
    for (char *p = str; *p != '\0'; p++)
    {
        is_neg = *p == '-' ? -1 : 1;
        num = num * 10 + (*p - 48);
    }
    num *= is_neg;
    return num;
}

/**
 * @brief Checks to see if a string contains a certain character
 *
 * @param s the string to be traversed
 * @param target the target character
 * @param len the length of the string
 * @return true if the character exists within the string
 * @return false if the character does not exist in the string
 */
bool has_char(char *s, char target, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (*(s + i) == target)
            return true;
    }
    return false;
}

/**
 * @brief the index of a target character in a string
 *
 * @param s the string to traverse
 * @param target the target char
 * @param len the length of the string
 * @return int the index of the char or -1 if not found
 */
int char_indexOf(char *s, char target, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (*(s + i) == target)
            return i;
    }
    return -1;
}

float str_to_sci_note(char *str)
{
}