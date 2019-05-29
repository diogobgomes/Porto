/* STDLIB.H - GENERAL PURPOSE STADART C/C++ LIBRARY
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

// Function to terminate execution abnormally. Dangerous!
__attribute__((__noreturn__))
void abort(void);

// -----------------------------------------------------------------------------
// Utility functions
// -----------------------------------------------------------------------------

// Converts string nptr to long integer. Modifies **endptr so that it points to 
// where it stopped reading the string (in case of overflow, or non-numerical
// characters). base is used to set in what base the string is written.
long int strtol(const char *nptr, char **endptr, int base);

// Converts string to integer
int atoi(const char *nptr);

// Converts integer to string
char *itoa(int value, char *dptr, int base);

// Converts unsigned integer to string
char *uitoa(unsigned int value, char *dptr, int base);

#ifdef __cplusplus
}
#endif

#endif
