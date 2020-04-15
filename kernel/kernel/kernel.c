/* MAIN KERNEL FILE
 *
 * After initializing the basic hardware, the boot assembly stubs pass control
 * over to kernel_main() (basically the kernel itself), defined in this file.
 *
 * Somewhat important
 *
 *
 * 2019 Diogo Gomes
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>

#include <kernel/tty.h>

void kernel_main(void);

void kernel_main(void) {
	terminal_initialize();
	char * c = "123";
	int i = strtol(c,NULL,0);

	printf("%i\n", i);
//	printf("%u",UINT_MAX);


/*	for(int i = 0; i < 99; i++) {
		printf("%i\n",i);
	}*/

}
