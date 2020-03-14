/* CTYPE.H - STANDARD C/C++ LIBRARY TO CLASSIFY AND TRANSFORM INDIVIDUAL
 * CHARACTERS
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#ifndef _CTYPE_H
#define _CTYPE_H 1

#ifdef __cplusplus
extern "C" {
#endif
	

// Macros for handling definition of inline functions
#ifndef INLINE
# define INLINE static inline
#endif

// -----------------------------------------------------------------------------
// istype functions
// -----------------------------------------------------------------------------

// All values taken from ASCII tables, look them up

// Returns 0 if c is not a ASCII digit, and 1 if c is an ASCII digit
INLINE int isdigit(int c) {
	return (c >= '0' && c <= '9') ? 1 : 0;
}

// Returns 1 if c is an ASCII hexadecimal digit, and 0 if it isn't
INLINE int isxdigit(int c) {
	return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
	? 1 : 0;
}

// Returns 1 if c is an ASCII space, and 0 if it isn't
INLINE int isspace(int c) {
	return c == ' ' ? 1 : 0;
}

// Returns 1 if c is an ASCII lowercase letter, and 0 if it isn't
INLINE int islower(int c) {
	return (c >= 'a' && c <= 'z') ? 1 : 0;
}

// Returns 1 if c is an ASCII uppercase letter, and 0 if it isn't
INLINE int isupper(int c) {
	return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

// Returns 1 if c is an ASCII alpha character, and 0 if it isn't
INLINE int isalpha(int c) {
	return islower(c) || isupper(c);
}

// Returns 1 if c is an ASCII alphanumerical character, and 0 if it isn't
INLINE int isalnum(int c) {
	return isalpha(c) || isdigit(c);
}

// Returns 1 if c is an ASCII control character, and 0 if it isn't
INLINE int iscntrl(int c) {
	return ((c >= 0 && c <= 31) || c == 127) ? 1 : 0;
}

// Returns 1 if c is an ASCII punctuation character, and 0 if it isn't
INLINE int ispunct(int c) {
	return ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96)
		|| (c >= 123 && c <= 126)) ? 1 : 0;
}

// Returns 1 if c is an ASCII printable character, and 0 if it isn't
INLINE int isprint(int c) {
	return (c >= 32 && c <= 126) ? 1 : 0;
}

// Returns 1 if c is representable in current settings, and 0 if it isn't
INLINE int isgraph(int c) {
	return (c >= 33 && c <= 126) ? 1 : 0;
}

// -----------------------------------------------------------------------------
// Capitalization functions
// -----------------------------------------------------------------------------

// Converts c to lowercase ASCII
INLINE int tolower( int c ) {
	return isupper(c) ? (c + 'a'-'A') : c;
}

// Converts c to uppercase ASCII
INLINE int toupper( int c ) {
	return islower(c) ? (c - 'a'+'A') : c;
}


#ifdef __cplusplus
}
#endif

#endif