/* TTY.C - DEFINITIONS FOR INTERACTING WITH A TTY-TYPE DEVICE
 *
 * Architecture dependent (i686-elf) implementation of the standart functions
 * defined in kernel/tty.h
 *
 *
 * 2019 Diogo Gomes
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>

#include "vga.h"

// Declaring some variables
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

// Set up the terminal: position (0,0), default light-grey on black color scheme,
// set up the VGA buffer.
void terminal_initialize(void) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

// TODO: figure out how the hell we'll handle colors
/*static void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}*/

// Internal function to put an entry c at position (x,y), with color code color
static void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

// Puts char c at the next entry in the terminal. Then it increments the column
// and row, dealing with line wrap. When it gets to the end of the screen, it
// simply returns to (0,0) and starts overwriting whathever's in there.
void terminal_putchar(char c) {
	unsigned char uc = (unsigned char)c; // Why would you send a negative char?
	terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}

// Writes a string data of lenght size to the terminal using terminal_putchar()
void terminal_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

// Basically a wrapper for terminal_write() that uses strlen to calculate the
// string lenght and then passes it onto terminal_write()
void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}
