/* ISTYPE.C - GLOBAL DEFINITIONS FOR INLINE FUNCTIONS IN CTYPE.H
 *
 * Custom made for Porto
 *
 * Basically what we're doing is defining global versions of inline functions
 * defined in ctype.h, so that, in case one call isn't inlined by the compiler,
 * there's still a default global version that can be called
 *
 *
 * 2019 Diogo Gomes
*/

// Defining the inline macro so that the included ctype.h will not define it,
// and functions will be declared plain and simple. Otherwise, when the header
// is included, they will see the 'extern inline' definition
#define INLINE
#include <ctype.h>