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

#ifdef __cplusplus
}
#endif

#endif
