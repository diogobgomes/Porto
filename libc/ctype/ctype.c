/* CTYPE.C - GLOBAL DEFINITIONS FOR THE FUNCTIONS IN CTYPE.H
 *
 * Custom made for Porto
 *
 * Basically what we're doing is defining global versions of inline functions
 * defined in ctype.h, so that, in case one call isn't inlined by the compiler,
 * there's still a default global version that can be called
 *
 *
 *
 * 2019 Diogo Gomes
*/

// Defining the inline macro so that the included ctype.h will not define it,
// and functions will be declared plain and simple. Otherwise, when the header
// is included, they will see the 'extern inline' definition
#include <ctype.h>

// Returns 0 if c is not a ASCII digit, and 1 if c is an ASCII digit
int isdigit(int c) {
	return (c >= '0' && c <= '9') ? 1 : 0;
}

// Returns 1 if c is an ASCII hexadecimal digit, and 0 if it isn't
int isxdigit(int c) {
	return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
	? 1 : 0;
}

// Returns 1 if c is an ASCII space, and 0 if it isn't
int isspace(int c) {
	return c == ' ' ? 1 : 0;
}

// Returns 1 if c is an ASCII lowercase letter, and 0 if it isn't
int islower(int c) {
	return (c >= 'a' && c <= 'z') ? 1 : 0;
}

// Returns 1 if c is an ASCII uppercase letter, and 0 if it isn't
int isupper(int c) {
	return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

// Returns 1 if c is an ASCII alpha character, and 0 if it isn't
int isalpha(int c) {
	return islower(c) || isupper(c);
}

// Returns 1 if c is an ASCII alphanumerical character, and 0 if it isn't
int isalnum(int c) {
	return isalpha(c) || isdigit(c);
}

// Returns 1 if c is an ASCII control character, and 0 if it isn't
int iscntrl(int c) {
	return ((c >= 0 && c <= 31) || c == 127) ? 1 : 0;
}

// Returns 1 if c is an ASCII punctuation character, and 0 if it isn't
int ispunct(int c) {
	return ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96)
		|| (c >= 123 && c <= 126)) ? 1 : 0;
}

// Returns 1 if c is an ASCII printable character, and 0 if it isn't
int isprint(int c) {
	return (c >= 32 && c <= 126) ? 1 : 0;
}

// Returns 1 if c is representable in current settings, and 0 if it isn't
int isgraph(int c) {
	return (c >= 33 && c <= 126) ? 1 : 0;
}

// -----------------------------------------------------------------------------
// Capitalization functions
// -----------------------------------------------------------------------------

// Converts c to lowercase ASCII
int tolower( int c ) {
	return isupper(c) ? (c + 'a'-'A') : c;
}

// Converts c to uppercase ASCII
int toupper( int c ) {
	return islower(c) ? (c - 'a'+'A') : c;
}
