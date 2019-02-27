/* PUTS.C - IMPLEMENTATION OF STDIO.H FUNCTION PUTS()
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <stdio.h>

// It's basically a simple wrapper for printf
int puts(const char* string) {
	return printf("%s\n", string);
}
