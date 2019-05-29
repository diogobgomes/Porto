/* STRTOL.C - IMPLEMENTATION OF STDLIB.H FUNCTION STRTOL
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <stdlib.h>
#include <ctype.h> // For isdigit(), isspace()
#include <stddef.h>

// TODO: handling other bases besides base 10 (that'll be our default for now), we really need this up and running ASAP

// We discard all whitespaces, then begin
long int strtol(const char *nptr, char **endptr, int base) {
	long int number = 0;
	while (isspace(*nptr))
		nptr++;
	while (*nptr) {
		if (isdigit(*nptr))
			number = number * 10 + *nptr;
		else {
			break;
		}
		nptr++;
	}
	*endptr = (*endptr == NULL ? NULL : (char *) nptr);
	return number;
}