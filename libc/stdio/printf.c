/* printf.c - stdio implementation of printf
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

// The function that actually prints things to std out
// Receives a string and it's lenght
// Returns true if everythings alright, or false if we reach EOF
// Uses the putchar function to actually print to std out, char by char
static bool print(const char* data, size_t length) {
	const unsigned char* bytes = (const unsigned char*) data;
	for (size_t i = 0; i < length; i++)
		if (putchar(bytes[i]) == EOF)
			return false;
	return true;
}

// The main job of this function is to format the string that it's passed to
// what actually will be printed, and then call print() to do the actual job.
// We're assuming a C type string, terminated by '\0'. If we don't get that, the
// function WILL overflow.
// The string can't be over INT_MAX lenght, if that should happen, we'll only
// print up until that point, and then return -1
int printf(const char* restrict format, ...) {
	va_list parameters;
	va_start(parameters, format);

	size_t written = 0;

	while (*format != '\0') {
		// No sign problem since INT_MAX is always positive
		size_t maxrem = (size_t) INT_MAX - written;

		if (format[0] != '%' || format[1] == '%') {
			if (format[0] == '%')
				format++;
			size_t amount = 1;
			while (format[amount] && format[amount] != '%')
				amount++;
			if (maxrem < amount) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, amount))
				return -1;
			format += amount;
			written += amount;
			continue;
		}

		const char* format_begun_at = format++;

		if (*format == 'c') {
			format++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(&c, sizeof(c)))
				return -1;
			written++;
		} else if (*format == 's') {
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else {
			format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, len))
				return -1;
			written += len;
			format += len;
		}
	}

	va_end(parameters);
	// No problem with this conversion, we have already made sure it won't
	// overflow
	return (int) written;
}
