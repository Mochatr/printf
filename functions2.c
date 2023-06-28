#include "main.h"

/**
 * print_pointer - It prints a pointer's value.
 * @types: Argument
 * @buffer: Argument
 * @flags: Argument
 * @width: Argument
 * @precision: Argument
 * @size: Parameter
 *
 * Return: the number of characters being printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char Extra_c = 0, Padd = ' ';
	int ind = BUFF_SIZE - 2, Length = 2;
	int Padd_S = 1;
	unsigned long num_add;
	char map_to[] = "0123456789abcdef";
	void *add = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (add == NULL)
	{
		return (write(1, "(nil)", 5));
	}

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_add = (unsigned long)add;

	while (num_add > 0)
	{
		buffer[ind--] = map_to[num_add % 16];
		num_add /= 16;
		Length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		Padd = '0';
	}
	if (flags & F_PLUS)
	{
		Extra_c = '+', length++;
	}
	else if (flags & F_SPACE)
	{
		Extra_c = ' ', Length++;
	}
	ind++;
	return (write_pointer(buffer, ind,
		Length, width, flags, Padd, Extra_c, Padd_S));
}
/**
 * print_non_printable - It prints ASCII codes in hexadecimal
 * of non printable characters
 * @types: Argument
 * @buffer: Argument
 * @flags: Argument
 * @width: Argument
 * @precision: Argument
 * @size: Parameter
 *
 * Return: the number of characters being printed.
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = 0, off_set = 0;
	char *string = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
	{
		return (write(1, "(null)", 6));
	}

	while (string[a] != '\0')
	{
		if (is_printable(str[a]))
		{
			buffer[a + off_set] = string[a];
		}
		else
		{
			off_set += append_hexa_code(string[a], buffer, a + off_set);
		}

		a++;
	}

	buffer[a + off_set] = '\0';

	return (write(1, buffer, a + off_set));
}

/**
 * print_reserve - It prints a string in reverse.
 * @types: Argument
 * @buffer: Argument
 * @flags: Argument
 * @width: Argument
 * @precision: Argument
 * @size: Parameter
 *
 * Return: the number of characters being printed.
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *string;
	int a, Count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(types, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")NULL(";
	}
	for (a = 0; string[a]; a++)
	{
		for (a = (a - 1); a >= 0; a--)
		{
			char x = string[a];

			write(1, &x, 1);
			Count++;
		}
	}
	return (Count);
}

/**
 * print_rot13string - It prints a string in rot13.
 * @types: Argument
 * @buffer: Argument
 * @flags: Argument
 * @width: Argument
 * @precision: Argument
 * @size: Parameter
 *
 * Return: the number of characters being printed.
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char z;
	char *string;
	unsigned int n, m;
	int Count = 0;
	char arr_in[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char arr_out[] =
"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
	{
		string = "(AHYY)";
	}

	for (n = 0; string[n]; n++)
	{
		for (m = 0; string[m]; m++)
		{
			if (arr_in[m] == string[n])
			{
				z = arr_out[m];
				write(1, &x, 1);
				Count++;
				break;
			}
		}
	}
	return (Count);
}
