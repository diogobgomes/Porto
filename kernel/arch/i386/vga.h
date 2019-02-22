#ifndef ARCH_I386_VGA_H
#define ARCH_I386_VGA_H

#include <stdint.h>

// TODO: if we ever upgrade to c++, check to see if we can change this enum type
// to uint_8 - there's no sense in declaring it as an int, but we are limited by
// constraints of C language
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

// Return the color code for printing to VGA given the foreground and background
// colors
static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
	return (uint8_t)(fg | bg << 4); // TODO: define operator | for uint8_t
}

// Returns the code to print the character to VGA, given a character and color
// information
static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t)(uc | color << 8); // TODO: define operator | for uint8_t
}

#endif
