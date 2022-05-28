#include <stdio.h>
#include <stdbool.h>
#include "custring.h"

/**
 * @brief Gets the length of the string
 *
 * @param str string to measure
 * @return int length of the string
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
 * @brief Checks to see if two strings are equal
 *
 * @param s1 first string
 * @param s2 second string
 * @return int 0 if true, 1 if false
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
 * @brief Checks to see if an array of strings contains a target string
 *
 * @param target the string to search for
 * @param arr the array of strings
 * @param arr_len length of the array
 * @return int 0 if true, 1 if false
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
 * @brief Finds the index of the string in the string array
 *
 * @param target the string to search for
 * @param arr the array of strings
 * @param arr_len length of the array
 * @return int i if the string exists within the array, else -1
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
 * @brief Custom atoi function
 *
 * @param str input numerical string
 * @return int integer value of the string
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

bool has_char(char *s, char target, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (*(s + i) == target)
            return true;
    }
    return false;
}

int char_indexOf(char *s, char target, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (*(s + i) == target)
            return i;
    }
    return -1;
}