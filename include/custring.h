#include <stdbool.h>

/**
 * @brief My custom implementation of strlen
 *
 * @param str the string to be traversed
 * @return int the length of the string, -1 if error
 */
int lenstr(char *str);

/**
 * @brief My custom implementation of strcmp
 *
 * @param s1 the first string to be compared
 * @param s2 the second string to be compared
 * @return true if the strings are a match
 * @return false if the strings don't match
 */
bool str_eq(char *s1, char *s2);

/**
 * @brief Checks to see if an array of strings contains a certain string
 *
 * @param target the target string we are searching for
 * @param arr the array of strings (most likely argv)
 * @param arr_len the length of the array
 * @return true if the string exists within the array
 * @return false if the string cannot be found
 */
bool has_str(char *target, char **arr, int arr_len);

/**
 * @brief finds the index of the first occurrence of a target string
 *
 * @param target the search string target
 * @param arr the array of strings to traverse
 * @param arr_len the length of the array
 * @return int the index of the string or -1 if not found
 */
int str_indexOf(char *target, char **arr, int arr_len);

/**
 * @brief My custom implementation of atoi
 *
 * @param str the numeric string to convert to an integer
 * @return int the numeric representation of the string
 */
int str_to_int(char *str);

/**
 * @brief a function to convert a numeric string to its
 * scientific notation equivalent
 *
 * @param str the numeric string
 * @return float the float representation of the sting
 */
float str_to_sci_note(char *str);

/**
 * @brief the index of a target character in a string
 *
 * @param s the string to traverse
 * @param target the target char
 * @param len the length of the string
 * @return int the index of the char or -1 if not found
 */
int char_indexOf(char *s, char target, int len);

/**
 * @brief Checks to see if a string contains a certain character
 *
 * @param s the string to be traversed
 * @param target the target character
 * @param len the length of the string
 * @return true if the character exists within the string
 * @return false if the character does not exist in the string
 */
bool has_char(char *s, char target, int len);