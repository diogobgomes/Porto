# BOOT ASSEMBLY STUB
#
# Small assembly stub that gets called from the bootloader, sets everything up
# for higher-level languages, and then transfers control over to kernel_main
#
#
# 2019 Diogo Gomes

# Declare constants for the multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
# The bootloader will search for this signature in the first 8 KiB of the kernel
# file, aligned at a 32-bit boundary.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve a stack for the initial thread.
# We need to provide a stack, and for that we'll create a symbol at the bottom
# of it, then allocate 16 KiB for it, and create a symbol at the top. The stack
# grows downwards on x86. We put it into it's own section so we can declare it
# as nobits, meaning our kernel file will be smaller. We need to make it 16-byte
# aligned according to the System V ABI.
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# The kernel entry point.
.section .text
.global _start
.type _start, @function
_start:
	# Set up the stack pointer
	movl $stack_top, %esp

	# Call the global constructors.
	call _init

	# Transfer control to the main kernel.
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
	cli
1:	hlt
	jmp 1b
.size _start, . - _start
