/* PRINTF.C - IMPLEMENTATION OF STDIO.H FUNCTION PRINTF()
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For itoa()

// For now, we'll use 20 as a buffer, it seems large enough, until we discover
// a better method (probably involving some janky macros)
#define BUFFER_LEN 20

// The main job of this function is to format the string that it's passed to
// what actually will be printed, and then call some function putfunc to do the 
// actual job.
// We're assuming a C type string, terminated by '\0'. If we don't get that, the
// function WILL overflow.
// The string can't be over INT_MAX lenght, if that should happen, we'll only
// process up until that point, and then return -1
// We receive a string to process (fmt), a va_list parameter list, and a pointer
// to a function (putfunc), which will print to the desired output, which must 
// receive a string and it's lenght, and return a bool
static int _outformat(const char* fmt, va_list params, bool (*putfunc)(const char*, size_t)) {
	size_t written = 0;

	while (*fmt != '\0') {
		// No sign problem since INT_MAX is always positive
		size_t maxrem = (size_t) INT_MAX - written;

		// Write the string until we find some format character
		if (fmt[0] != '%' || fmt[1] == '%') {
			if (fmt[0] == '%') // Checking for '%%' escape sequence
				fmt++;
			size_t amount = 1;
			while (fmt[amount] && fmt[amount] != '%')
				amount++;
			if (maxrem < amount) { // TODO: Check overflow conditions here (test)
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!(*putfunc)(fmt, amount))
				return -1;
			fmt += amount;
			written += amount;
			continue; // Need to continue in case we've reached '\0'
		}

		// We've already determined it's a format string, we want to know what
		// it is
		const char* const format_begun_at = fmt++;


		switch (*fmt) {
			case 'c': { // Char	
				fmt++;
				char c = (char) va_arg(params, int /* char promotes to int */);
				if (!maxrem) {
					// TODO: Set errno to EOVERFLOW.
					return -1;
				}
				if (!(*putfunc)(&c, sizeof(c)))
					return -1;
				written++;
				break;
			} case 's': { // String
				fmt++;
				const char* str = va_arg(params, const char*);
				size_t len = strlen(str);
				if (maxrem < len) {
					// TODO: Set errno to EOVERFLOW.
					return -1;
				}
				if (!(*putfunc)(str, len))
					return -1;
				written += len;
				break;
			} case 'i': case 'd': { // Signed integer
				fmt++;
				int num = va_arg(params, int);
				char str[BUFFER_LEN];
				itoa(num,str,10);
				size_t len = strlen(str);
				if (maxrem < len) {
					// TODO: Set errno to EOVERFLOW
					return -1;
				}
				if (!(*putfunc)(str, len))
					return -1;
				written += len;
				break;
			} case 'u': { // Unsigned integer
				fmt++;
				unsigned int num = va_arg(params, unsigned int);
				char str[BUFFER_LEN];
				uitoa(num,str,10);
				size_t len = strlen(str);
				if (maxrem < len) {
					// TODO: Set errno to EOVERFLOW
					return -1;
				}
				if (!(*putfunc)(str, len))
					return -1;
				written += len;
				break;
			} default: { // Default: if we have a bad format, just print the
						 // rest of the string
				fmt = format_begun_at;
				size_t len = strlen(fmt);
				if (maxrem < len) {
					// TODO: Set errno to EOVERFLOW.
					return -1;
				}
				if (!(*putfunc)(fmt, len))
					return -1;
				written += len;
				fmt += len;
				break;
			}
		}		
	}

	// No problem with this conversion, we have already made sure it won't
	// overflow
	return (int) written;

}

// The function that actually prints things to std out
// Receives a string and it's lenght
// Returns true if everythings alright, or false if we reach EOF
// Uses the putchar function to actually print to std out, char by char
static bool _terminalprint(const char* data, size_t length) {
	const unsigned char* bytes = (const unsigned char*) data;
	for (size_t i = 0; i < length; i++)
		if (putchar(bytes[i]) == EOF)
			return false;
	return true;
}

// Formatted printing to stdout - just a wrapper for _outformat
int printf(const char* format, ...) {
	va_list parameters;
	va_start(parameters, format);

	size_t written = _outformat(format, parameters, &_terminalprint);

	va_end(parameters);
	// No problem with this conversion, _outformat actually returns a positive
	// int
	return (int) written;
}
