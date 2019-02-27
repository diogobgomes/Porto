/* MEMMOVE.C - IMPLEMENTATION OF STRING.H FUNCTION MEMMOVE
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <string.h>

// Does the same as memcpy, but works if memories overlap. For that, we test if
// srcptr is higher than dstptr, and in case it is, we start from the top and
// work our way to the bottom, so that we don't overwrite the source before we
// have copied it
void* memmove(void* dstptr, const void* srcptr, size_t size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	if (dst < src) {
		for (size_t i = 0; i < size; i++)
			dst[i] = src[i];
	} else {
		for (size_t i = size; i != 0; i--)
			dst[i-1] = src[i-1];
	}
	return dstptr;
}
