/* STRTOL.C - IMPLEMENTATION OF STDLIB.H FUNCTION STRTOL
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

long int strtol(const char *nptr, char **endptr, int base) {
	// Check for a valid base
	if( base != 0 && (base < 2 || base > 36) ) {endptr = NULL; return 0;}

	// Discard whitespaces
	while(*nptr == ' ') nptr++;

	// Deal with signs
	bool sign = false;
	if( *nptr == '-') { sign = true; ++nptr; }

	// Deal with strange input formats required by standart
	if( !base )  { // base == 0
		if( *nptr == '0' ) {
			if ( *(++nptr) == 'x' )
				base = 16;
			else
				base = 8;
			++nptr;
		} else 
			base = 10;
	}

	// Deal with base 16 formatting
	if ( *nptr == '0' && base == 16 && *++nptr == 'x')
		++nptr;

	// Number to return
	long int num = 0;

	const char symbols[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	while(*nptr) {
		const char *ptr;
		int i;
		if( ((ptr = strchr(symbols,tolower(*nptr))) != NULL) && // Is a valid number
		( i = (ptr - symbols)/(int)sizeof(*ptr) ) <= base ) { // Validates base
			num = num * base + i;		
		} else { // Stopped being a valid number
			// This assignment is fine, we're supposed to leave endptr as non-const
			endptr = (endptr == NULL ? NULL : (char**)&nptr);
			return (sign ? -num : num);
		}
		++nptr;
	}
	// This assignment is fine, we're supposed to leave endptr as non-const
	endptr = (endptr == NULL ? NULL : (char**)&nptr);
	return (sign ? -num : num);
}