#include "main.h"

/**
 * print_unsigned - Function that prints unsigned number.
 * @types: Argument
 * @buffer: Argument
 * @flags: Argument
 * @width: Argument
 * @precision: Argument
 * @size: Argument
 *
 * Return: the number of characters that is printed.
 */

int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
	{
		buffer[n--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[n--] = (number % 10) + '0';
		number /= 10;
	}

	n++;
	return (write_unsgnd int(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Function that prints unsigned num in Octal notation.
 * @types: Argument
 * @buffer: Argument
 * @flags: Argument
 * @width: Argument
 * @precision: Argument
 * @size: Argument
 *
 * Return: the number of characters that is printed.
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int init_Num = number;

	UNUSED(width);
	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[a--] = '\0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[a--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_Num != 0)
	{
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - It prints unsigned num in hexa
 * @types: Argument
 * @buffer: Argument
 * @flags: Argument
 * @width: Argument
 * @precision: Argument
 * @size: Argument
 *
 * Return: the number of characters being printed.
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Function that prints unsigned num in uppercase hexa
 * @types: Argument
 * @buffer: Argument
 * @flags: Argument
 * @width: Argument
 * @precision: Argument
 * @size: Argument
 *
 * Return: the number of characters being printed.
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * print_hexa - prints a hexa number
 * in lower or upper.
 * @types: Argument
 * @buffer: Argument
 * @map_to: Parameter
 * @flags: Argument
 * @flig_ch: Parameter
 * @width: Argument
 * @precision: Argument
 * @size: Argument
 * @size: Parameter
 *
 * Return: the number of characters being printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flig_ch, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int initialNum = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[n--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && initial_Num != 0)
	{
		buffer[n--] = flag_ch;
		buffer[n--] = '0';
	}

	n++;

	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}

