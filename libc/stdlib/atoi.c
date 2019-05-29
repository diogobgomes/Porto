/* ATOI.C - IMPLEMENTATION OF STDLIB.H FUNCTION ATOI
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <stdlib.h>
#include <stddef.h>

// 
int atoi(const char *nptr) {
	return strtol(nptr, NULL, 10);
}