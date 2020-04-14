/*******************************************************************************
 * @file stdlib.h
 * @brief General purposed standard C/C++ library
 * 
 * @note Custom made for Porto
 * 
 * 
 * @date 2019-2020
 * @author Diogo Gomes
 ******************************************************************************/

#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief      Function to terminate execution abnormally. Dangerous!
 * @warning    Defined with __attribute__((__noreturn__))
 */
__attribute__((__noreturn__))
void abort(void);

// -----------------------------------------------------------------------------
// Utility functions
// -----------------------------------------------------------------------------

/**
 * @brief      Converts a string to long integer
 *
 * @param[in]  nptr    String to be converted
 * @param[out] endptr  Modified so that it points to where it stopped reading
 * the string (in case of overflow, or non-numerical characters)
 * @param[in]  base    Used to set in what base the string is written
 *
 * @return     The number read from the string
 */
long int strtol(const char *nptr, char **endptr, int base);

/**
 * @brief      Converts a string to an integer
 *
 * @param[in]  nptr  String to be converted
 *
 * @return     The number read from the string
 */
int atoi(const char *nptr);

/**
 * @brief      Converts integer to string
 * @warning    Fails on the largest possible negative number
 *
 * @param[in]  value  The number to be converted
 * @param[out] dptr   Destination string, must be big enough to hold the number
 * @param[in]  base   The base in which the number is to be written
 *
 * @return     Destination string
 */
char *itoa(int value, char *dptr, int base);

/**
 * @brief      Converts unsigned integer to string
 *
 * @param[in]  value  The number to be converted
 * @param[out] dptr   Destination string, must be big enough to hold the number
 * @param[in]  base   The base in which the number is to be written
 *
 * @return     Destination string
 */
char *uitoa(unsigned int value, char *dptr, int base);

#ifdef __cplusplus
}
#endif

#endif
