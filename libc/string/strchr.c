/* STRTOL.C - IMPLEMENTATION OF STDLIB.H FUNCTION STRTOL
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <string.h>

char* strchr(const char* str, char c) {
	while(*str) {
		if(*str == c) {
			// The const keyword was just indicative to us, this is fine for our
			// purposes
			return (char*) str;
		}
		++str;
	}
	return NULL;
}