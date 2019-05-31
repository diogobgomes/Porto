/* CTYPE.H - STANDARD C/C++ LIBRARY TO CLASSIFY AND TRANSFORM INDIVIFUAL
 * CHARACTERS
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#ifndef _CTYPE_H
#define _CTYPE_H 1

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
// istype functions
// -----------------------------------------------------------------------------

// All values taken from ASCII tables, look them up

// Macros for handling definition of inline functions, see istype.c
#ifndef INLINE
# define INLINE extern inline
#endif

int isdigit( int c );
int isxdigit( int c );
int isspace( int c );
int islower( int c );
int isupper( int c );
int isalpha( int c );
int isalnum( int c );
int iscntrl( int c );
int ispunct( int c );
int isprint( int c );
int isgraph( int c );

int toupper( int c );
int tolower( int c );

#ifdef __cplusplus
}
#endif

#endif