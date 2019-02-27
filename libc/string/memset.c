/* MEMSET.C - IMPLEMENTATION OF STRING.H FUNCTION MEMSET
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <string.h>

// Defined in header, we're not doing anything special here
void* memset(void* bufptr, int value, size_t size) {
	unsigned char* buf = (unsigned char*) bufptr;
	for (size_t i = 0; i < size; i++)
		buf[i] = (unsigned char) value;
	return bufptr;
}
