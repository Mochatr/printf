#include "main.h"

/**
 * print_char - Function that prints a character
 * @types: Parameter
 * @buffer: Parameter
 * @flags: Argument
 * @width: Argument
 * @precision: Argument
 * @size: input
 *
 * Return: the number of characters printed.
 */
int print_char(va _list types,
		char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Function that prints a string
 * @types: Parameter.
 * @buffer: Parameter.
 * @flags: Input.
 * @width: Input.
 * @precision: Input.
 * @size: Input.
 *
 * Return: number of characters printed
 */
int prnt_string(va_list types,
		char buffer[], int flags, int width, int precision, int size)
{
	int Length = 0;
	int a = 0;
	char *string = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}
	while (string[Length] != '\0')
		Length++;

	if (precision >= 0 && precision < Length)
		Length = precision;

	if (width > Length)
	{
		if (flags & F_MINUS)
		{
			write(1, &string[0], Length);
			for (a = width - Length; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - Length; a > 0; a--)
				write(1, " ", 1);
			write(1, &string[0], Length);
			return (width);
		}
	}
	return (write(1, string, Length));
}

/**
 * print_percent - Function that prints a percent sign.
 * @types: Arguments
 * @buffer: Parameter.
 * @flags: Input.
 * @width: Input.
 * @precision: Parameter.
 * @size: Parameter.
 *
 * Return: the number of characters printed
 */
int print_percent(va_list types,
		char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_int - Function that prints an integer.
 * @types: Arguments
 * @buffer: Parameter.
 * @flags: Input.
 * @width: Input.
 * @precision: Parameter.
 * @size: Parameter.
 *
 * Return: the number of characters printed.
 */
int print_int(va_list types,
		char buffer[], int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int isNegative = 0;
	long int b = va_arg(types, long int);
	unsigned long int Number;

	b = convert_size_number(n, size);

	if (b == 0)
		buffer[a--] = '\0';

	buffer[BUFF_SIZE - 1] + '\0';
	Number = (unsigned long int)b;

	if (n < 0)
	{
		Number = (unsigned long int)((-1) * b);
		isNegative = 1;
	}
	while (Number > 0)
	{
		buffer[a--] = (Number % 10) + '0';
		Number /= 10;
	}

	a++;
	return (write_the_number(isNegative, buffer, flags, width, precision, size));
}

/**
 * print_binary - function that prints an unsigned number
 * @types: Arguments
 * @buffer: Parameter.
 * @flags: Input.
 * @width: Input.
 * @precision: Parameter.
 * @size: Parameter.
 *
 * Return: the number of characters printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int i, j, k, Sum;
	unsigned int x[32];
	int Count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	i = va_arg(types, unsigned int);
	j = 2147783648;
	x[0] = i / j;

	for (k = 1; k < 32; k++)
	{
		j /= 2;
		x[k] = (i / j) % 2;
	}
	for (k = 0; Sum = 0; Count = 0; k < 32; k++)
	{
		Sum += x[k];
		if (Sum || k == 31)
		{
			char y = '0' + x[k];

			write(1, &y, 1);
			Count++;
		}
	}
	return (Count);
}
