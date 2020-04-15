/* ITOA.C - IMPLEMENTATION OF STDLIB.H FUNCTION ITOA
 * NOT ANSI-C DEFINED!! WE'LL SUPPORT IT ANYWAY
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <stdlib.h>

//FIXME: FAILS ON THE LARGEST POSSIBLE NEGATIVE NUMBER!!!

char *itoa(int value, char *dptr, int base) {
	// Checking if the base is valid
	// Valid bases are between 2 and 36 (whole alphabet + numerals 0-9)
	if( base < 2 || base > 36 ) {*dptr = 0; return dptr;}

	// Create two pointers, so we don't mess with dptr directly
	char *wrtptr = dptr;
	char *tmpptr = dptr;

	// Absolut of value, store state of sign
	int absvalue = value;
	int sign = 0;
	if( value < 0) {
		sign = 1;
		absvalue = -value;
	}

	// Possible symbols, for any base
	const char symbols[] = "0123456789abcdefghijklmnopqrstuvwxyz";

	// Do cycle, creates the string reversed
	do {
		int tmp = absvalue / base;
		*wrtptr = symbols[absvalue - tmp*base];
		++wrtptr; absvalue = tmp;
	} while( absvalue );

	// Append a sign if necessary
	if( sign ) *wrtptr++ = '-';
	*wrtptr-- = 0;

	// Invert the string
	while(tmpptr < wrtptr) {
		char tmp = *tmpptr;
		*tmpptr++ = *wrtptr;
		*wrtptr-- = tmp;
	}

	return dptr;
}