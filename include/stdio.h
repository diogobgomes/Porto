/* stdio.h - standart I/O functions for C/C++
 * Custom made for Porto
 *
 * printf, putchar, puts
 *
 *
 * 2019 Diogo Gomes
*/

#ifndef _STDIO_H
#define _STDIO_H 1

#include <sys/cdefs.h>

#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif

// Prints to std out (in principle, that would be the screen)
// First argument is the string to print, all the following are format
// moddifiers
// Returns how much was written, or -1 if there's any errors
int printf(const char* __restrict, ...);

// Prints a single character to std out (in principle, that would be the screen)
int putchar(int);

// 
int puts(const char*);

#ifdef __cplusplus
}
#endif

#endif
