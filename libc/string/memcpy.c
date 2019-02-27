/* MEMCPY.C - IMPLEMENTATION OF STRING.H FUNCTION MEMCPY
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <string.h>

// Defined in header, we're not doing anything special
void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	for (size_t i = 0; i < size; i++)
		dst[i] = src[i];
	return dstptr;
}
