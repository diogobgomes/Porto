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

#include <kernel/tty.h>

void kernel_main(void);

void kernel_main(void) {
	terminal_initialize();
	printf("Hello kernel world!\n");
}
