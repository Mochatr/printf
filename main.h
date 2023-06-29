#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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
 * struct format - Struct op
 *
 * @format: The format.
 * @f: The function associated.
 */
struct format
{
char format;
int (*f)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_tp - Struct op
 *
 * @format: The format.
 * @format_t: The function associated.
 */
typedef struct format format_tp;

int _printf(const char *format, ...);
int handle_print(const char *format, int *a, va_list va, char buff[],
	int ks, int ma, int sap, int bt);


int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list va);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int handle_write_char(char c, char buff[],
	int ta, int wa, int pa, int sa);
int write_number(int num_neg, int i, char buff[],
	int ta, int wa, int pa, int sa);
int write_num(int i, char buff[],
	int ta, int wa, int pa,
	int len, char pd, char c);
int write_pointer(char buff[], int i, int len,
	int wa, int ta, char pd, char c, int pds);
int write_unsgnd(int num_neg, int i,
	char buff[],
	int ta, int wa, int pa, int sa);

int is_printable(char c);
int append_hexa_code(char dig, char buff[], int i);
int is_digit(char c);

long int convert_size_number(long int a, int sz);
long int convert_size_unsgnd(unsigned long int a, int sz);

#endif /* MAIN_H */

