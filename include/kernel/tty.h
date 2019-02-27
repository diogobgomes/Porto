/* TTY.H - INTERACTION WITH A TTY-TYPE DEVICE
 *
 * Defines standart functions for interacting with a tty-type device.
 * Used for writing to a monitor before we have proper drivers
 *
 *
 * 2019 Diogo Gomes
*/

#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>

// Sets up the terminal. Simply call it once, and we're good to go
void terminal_initialize(void);

// Puts a char c at the next entry in the terminal. Be carefull with the
// argument you pass it, for performance reasons it will not be checked
void terminal_putchar(char c);

// Writes a string data of lenght size to the terminal. Be carefull with the
// argument you pass it, for performance reasons it will not be checked
void terminal_write(const char* data, size_t size);

// Writes a string data to the terminal. Call this instead of terminal_write, as
// this one will strlen() the string.
void terminal_writestring(const char* data);

#endif
