/*******************************************************************************
 * @file ctype.h
 * @brief Standard C/C++ library to classify and transform individual characters
 * 
 * @note Custom made for Porto
 * 
 * 
 * @date 2019-2020
 * @author Diogo Gomes
 ******************************************************************************/

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

/**
 * @brief Tests if it's an ASCII digit
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not an ASCII digit, and 1 if it is
*/
INLINE int isdigit(int c) {
	return (c >= '0' && c <= '9') ? 1 : 0;
}


/**
 * @brief Tests if it's an ASCII hexadecimal digit
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not an ASCII hexadecimal digit, and 1 if it is
*/
INLINE int isxdigit(int c) {
	return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
	? 1 : 0;
}


/**
 * @brief Tests if it's an ASCII space
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not an ASCII space, and 1 if it is
*/
INLINE int isspace(int c) {
	return c == ' ' ? 1 : 0;
}


/**
 * @brief Tests if it's an ASCII lowercase letter
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not an ASCII lowercase letter, and 1 if it is
*/
INLINE int islower(int c) {
	return (c >= 'a' && c <= 'z') ? 1 : 0;
}


/**
 * @brief Tests if it's an ASCII uppercase letter
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not an ASCII uppercase letter, and 1 if it is
*/
INLINE int isupper(int c) {
	return (c >= 'A' && c <= 'Z') ? 1 : 0;
}


/**
 * @brief Tests if it's an ASCII alpha character
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not an ASCII alpha character, and 1 if it is
*/
INLINE int isalpha(int c) {
	return islower(c) || isupper(c);
}


/**
 * @brief Tests if it's an ASCII alphanumerical character
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not an ASCII alphanumerical character, and 1 if it is
*/
INLINE int isalnum(int c) {
	return isalpha(c) || isdigit(c);
}


/**
 * @brief Tests if it's an ASCII control character
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not an ASCII control character, and 1 if it is
*/
INLINE int iscntrl(int c) {
	return ((c >= 0 && c <= 31) || c == 127) ? 1 : 0;
}


/**
 * @brief Tests if it's an ASCII punctuation character
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not an ASCII punctuation character, and 1 if it is
*/
INLINE int ispunct(int c) {
	return ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96)
		|| (c >= 123 && c <= 126)) ? 1 : 0;
}


/**
 * @brief Tests if it's an ASCII printable character
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not an ASCII printable character, and 1 if it is
*/
INLINE int isprint(int c) {
	return (c >= 32 && c <= 126) ? 1 : 0;
}


/**
 * @brief Tests if a character is representable in current settings
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be tested
 * 
 * @return 0 if c is not representable in current settings, and 1 if it is
*/
INLINE int isgraph(int c) {
	return (c >= 33 && c <= 126) ? 1 : 0;
}

// -----------------------------------------------------------------------------
// Capitalization functions
// -----------------------------------------------------------------------------


/**
 * @brief Converts a character to lowercase ASCII
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be converted
 * 
 * @return the ASCII lowercase character, or the character itself if there's no \
 lowercase representation
*/
INLINE int tolower( int c ) {
	return isupper(c) ? (c + 'a'-'A') : c;
}


/**
 * @brief Converts a character to uppercase ASCII
 * 
 * @note This function is 'static inline', in principle
 * 
 * @param[in] c Character to be converted
 * 
 * @return the ASCII uppercase character, or the character itself if there's no \
 uppercase representation
*/
INLINE int toupper( int c ) {
	return islower(c) ? (c - 'a'+'A') : c;
}


#ifdef __cplusplus
}
#endif

#endif
