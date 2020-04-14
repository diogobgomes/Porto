/*******************************************************************************
 * @file string.h
 * @brief Standard string operations for C/C++
 * 
 * @note Custom made for Porto
 * 
 * 
 * @date 2019-2020
 * @author Diogo Gomes
 ******************************************************************************/

#ifndef _STRING_H
#define _STRING_H 1

#include <sys/cdefs.h>

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief      Compare bytes in memory
 * @details    Compares bytes in memory up to size byte, and return the result
 * of the comparison
 *
 * @param[in]  aptr  Pointer to 1st address
 * @param[in]  bptr  Pointer to 2nd address
 * @param[in]  size  Number of bytes to compare
 *
 * @return     Return <0 for aptr < bptr, >0 for aptr > bptr, and 0 for aptr = bptr
 */
int memcmp(const void* aptr, const void* bptr, size_t size);

/**
 * @brief      Copies memory from one location to the other
 * @warning    Doesn't work in memory with overlapping areas, for that use
 * memmove()
 *
 * @param[out] dstptr  Pointer to the destination in memory
 * @param[in]  srcptr  Pointer to the source in memory
 * @param[in]  size    Number of bytes to be copied
 *
 * @return     Returns the destination pointer (dstptr)
 */
void* memcpy(void* __restrict dstptr, const void* __restrict srcptr, size_t size);

/**
 * @brief      Copies memory from one location to the other
 * @details    Does the same as memcpy() but works in memory with overlapping
 * areas
 *
 * @param[out] dstptr  Pointer to the destination in memory
 * @param[in]  srcptr  Pointer to the source in memory
 * @param[in]  size    Number of bytes to be copied
 *
 * @return     Returns the destination pointer (dstptr)
 */
void* memmove(void* dstptr, const void* srcptr, size_t size);

/**
 * @brief      Set memory to a value
 *
 * @param[out] bufptr  Pointer to memory to be set
 * @param[in]  value   Value to be set in bufptr
 * @param[in]  size    Number of bytes to be set
 *
 * @return     Returns the pointer (bufptr)
 */
void* memset(void* bufptr, int value, size_t size);

/**
 * @brief      Calculate the lenght of a string
 *
 * @param[in]  str   C type string whose lenght we wish to calculate
 *
 * @return     The lenght of the string
 */
size_t strlen(const char* str);

/**
 * @brief      Locate the first occurrence of a character in a string
 *
 * @param[in]  str   C type tring to be searched
 * @param[in]  c     Character to be searched
 *
 * @return     A pointer to the first occurrence of c in str, or NULL if none is
 * found
 */
char* strchr(const char* str, char c);

#ifdef __cplusplus
}
#endif

#endif
