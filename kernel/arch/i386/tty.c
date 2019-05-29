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

// Internal function to clear the screen. Fills it with spaces, with color
// 'terminal_color', and sets the cursor back to the beginning
static void terminal_clear(void) {
	terminal_row = 0;
	terminal_column = 0;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

// Set up the terminal: position (0,0), default light-grey on black color scheme,
// set up the VGA buffer.
void terminal_initialize(void) {
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	terminal_clear();
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

// Internal function to scroll the screen. It copies all lines from line 1 to
// the line above it. Also terminal_row--.
static void terminal_scroll(void) {
	terminal_row--;
	for (size_t y = 1; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index_src = y * VGA_WIDTH + x;
			const size_t index_dest = (y - 1) * VGA_WIDTH + x;
			terminal_buffer[index_dest] = terminal_buffer[index_src];
		}
	}
	for (size_t x = 0; x < VGA_WIDTH; x++) {
		const size_t index = (VGA_HEIGHT - 1) * VGA_WIDTH + x;
		terminal_buffer[index] = vga_entry(' ', terminal_color);
	}
}

// Puts char c at the next entry in the terminal. Then it increments the column
// and row, dealing with line wrap. When it gets to the end of the screen, it
// simply returns to (0,0) and starts overwriting whathever's in there.
void terminal_putchar(char c) {
	// We scroll at the beginning and not right when there's a new line so that
	// the last line of the screen can still be used - we only need to check to
	// scroll if we're going to actually write something
	if (terminal_row == VGA_HEIGHT)
		terminal_scroll();
	unsigned char uc = (unsigned char)c; // Why would you send a negative char?
	
	// Handling newlines (pretty much the same as an end of line)
	if (uc == (unsigned char)'\n') {
		terminal_column = 0;
		terminal_row++;
		return;
	}
	terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		terminal_row++;
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
