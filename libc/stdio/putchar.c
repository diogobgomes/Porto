/* PUTCHAR.C - IMPLEMENTATION OF STDIO.H FUNCTION PUTCHAR()
 *
 * Custom made for Porto
 *
 *
 * 2019 Diogo Gomes
*/

#include <stdio.h>

#if defined(__is_libk)
#include <kernel/tty.h>
#endif

// TODO: Return -1 if error
// Prints a single char to stdout. It's most often used as a backend for more
// common functions such as printf
int putchar(int ic) {
#if defined(__is_libk)
	// In libk mode, for performance reasons, it won't perform checks on the
	// input. We use terminal_write() as the backend for this function
	char c = (char) ic;
	terminal_write(&c, sizeof(c));
#else
	// TODO: Implement stdio and the write system call.
#endif
	return ic;
}
