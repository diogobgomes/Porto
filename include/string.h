/* STRING.H - STANDART STRING OPERATIONS FOR C/C++
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#ifndef _STRING_H
#define _STRING_H 1

#include <sys/cdefs.h>

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Compares bytes in memory up to size byte. Returns <0 for aptr less than bptr,
// >0 for aptr greater than bptr, and 0 for both the same
int memcmp(const void* aptr, const void* bptr, size_t size);

// Copies size bytes from srcptr to dstptr, returns dstptr
void* memcpy(void* __restrict dstptr, const void* __restrict srcptr, size_t size);

// Copies size bytes from srcptr to dstptr. Works in memory with overlapping
// areas. Returns dstprt
void* memmove(void* dstptr, const void* srcptr, size_t size);

// Sets size values in bufptr to value, returns bufptr
void* memset(void* bufptr, int value, size_t size);

// Returns the lenght of str (str is a C type string)
size_t strlen(const char* str);

// Locate the first occurrence of character in string
char* strchr(const char* str, char c);

#ifdef __cplusplus
}
#endif

#endif
