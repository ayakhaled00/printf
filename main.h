#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct spec - struct the token specifier
 * @spec: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct spec
{
	char spec;
	int (*f)(va_list, flags_t *);
} spec_t;


/**
 * struct flags - struct the flags
 * @plus: flag for the '+'
 * @hash: flag for the '#'
 * @space: flag for the ' '
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;


int _printf(const char *format, ...);

int print_string(va_list o, flags_t *f);
int print_int(va_list o, flags_t *f);
int print_hex_big(va_list o, flags_t *f);
int print_binary(va_list o, flags_t *f);
int print_unsigned(va_list o, flags_t *f);
int print_hex(va_list o, flags_t *f);
int print_octal(va_list o, flags_t *f);
int get_flag(char s, flags_t *f);
int print_char(va_list o, flags_t *f);
int print_address(va_list o, flags_t *f);
int print_percent(va_list o, flags_t *f);

int print_rot13(va_list o, flags_t *f);
int print_rev(va_list o, flags_t *f);
int print_bigS(va_list o, flags_t *f);

int count_digit(int i);
void print_number(int n);

char *convert(unsigned long int num, int base, int lowercase);

int (*get_speci(char s))(va_list, flags_t *);

int _putchar(char c);
int _puts(char *str);

#endif

