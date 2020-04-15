/* ABORT.C - IMPLEMENTATION OF STDLIB.H FUNCTION ABORT()
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <stdio.h>
#include <stdlib.h>

// Terminates execution abnormally, in libk mode should call a kernel panic of
// some sort. For now, it simply prints and does nothing (so yeah, completely 
// useless, dangerous garbage)

__attribute__((__noreturn__))
void abort(void) {
#if defined(__is_libk)
	// TODO: Add proper kernel panic.
	printf("kernel: panic: abort()\n");
#else
	// TODO: Abnormally terminate the process as if by SIGABRT.
	printf("abort()\n");
#endif
	while (1) { }
	__builtin_unreachable();
}
