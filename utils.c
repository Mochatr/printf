#include "main.h"

/**
 * is_printable - Function
 * @c: Parameter
 *
 * Return: 1 else 0
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Function
 * @dig: Parameter
 * @buff: Parameter
 * @i: Parameter
 * Return: Always 3
 */

int append_hexa_code(char dig, char buff[], int i)
{
	char tab_hex[] = "0123456789ABCDEF";

	if (dig < 0)
		dig *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	buff[i++] = tab_hex[dig / 16];
	buff[i] = tab_hex[dig % 16];

	return (3);
}

/**
 * is_digit - Function
 * @c: Parameter
 *
 * Return: 1 else 0
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Function
 * @a: Parameter
 * @sz: Parameter
 *
 * Return: Casted value of a
 */

long int convert_size_number(long int a, int sz)
{
	if (sz == S_LONG)
		return (a);
	else if (sz == S_SHORT)
		return ((short)a);

	return ((int)a);
}

/**
 * convert_size_unsgnd - Function
 * @a: Parameter
 * @sz: Parameter
 *
 * Return: Casted value of a
 */

long int convert_size_unsgnd(unsigned long int a, int sz)
{
	if (sz == S_LONG)
		return (a);
	else if (sz == S_SHORT)
		return ((unsigned short)a);

	return ((unsigned int)a);
}
