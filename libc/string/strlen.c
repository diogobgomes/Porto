/* STRLEN.C - IMPLEMENTATION OF STRING.H FUNCTION STRLEN
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <string.h>

// Defined in header, we're not doing anything special here
size_t strlen(const char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}
