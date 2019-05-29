/* UITOA.C - IMPLEMENTATION OF STDLIB.H FUNCTION ITOA
 * NOT ANSI-C DEFINED!! WE'LL SUPPORT IT ANYWAY
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <stdlib.h>

char *uitoa(unsigned int value, char *dptr, int base) {
	// Checking if the base is valid
	// Valid bases are between 2 and 36 (whole alphabet + numerals 0-9)
	if( base < 2 || base > 36 ) {*dptr = 0; return dptr;}

	// Create two pointers, so we don't mess with dptr directly
	char *wrtptr = dptr;
	char *tmpptr = dptr;

	// Possible symbols, for any base
	char symbols[] = "0123456789abcdefghijklmnopqrstuvwxyz";

	// Do cycle, creates the string reversed
	do {
		unsigned int tmp = value / (unsigned int) base;
		// Conversion to unsigned int is safe, we don't allow negative bases
		*wrtptr = symbols[value - tmp*(unsigned int) base];
		++wrtptr; value = tmp;
	} while( value );

	// Terminating the string
	*wrtptr-- = 0;

	// Invert the string
	while(tmpptr < wrtptr) {
		char tmp = *tmpptr;
		*tmpptr++ = *wrtptr;
		*wrtptr-- = tmp;
	}

	return dptr;
}