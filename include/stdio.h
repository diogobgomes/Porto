/*******************************************************************************
 * @file stdio.h
 * @brief Standard I/O functions for C/C++
 * 
 * @note Custom made for Porto
 * 
 * 
 * @date 2019-2020
 * @author Diogo Gomes
 ******************************************************************************/ 

#ifndef _STDIO_H
#define _STDIO_H 1

#include <sys/cdefs.h>

#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief      Prints to stdout
 * @note       For now, that's just the screen
 * @note       For now, we only support ASCII
 *
 * @param[in]  format  Formated string to print
 * @param[in]  ...  Format modifiers
 *
 * @return     Number of characters written, or -1 if there's any errors 
 */
int printf(const char* __restrict format, ...);

/**
 * @brief      Prints a single character to stdout
 * @details    It's most often used as a backend for more common functions such
 * as printf(). We use terminal_write() as the backend for this function
 * @warning    In libk mode, for performance reasons, it won't perform checks on
 * the input
 * @note       For now, that's just the screen
 *
 * @param[in]  ic  ASCII character to be written
 *
 * @return     The input character
 */
int putchar(int ic);

/**
 * @brief      Prints a string to stdout, appending a newline
 * @details    Uses printf() as a backend
 *
 * @param[in]  string  String to be written
 *
 * @return     The output from printf(): the number of characters written
 */
int puts(const char* string);

#ifdef __cplusplus
}
#endif

#endif
