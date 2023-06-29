#include "main.h"

/**
 * print_pointer - Function
 * @tp: parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int print_pointer(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	char c = 0, pd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, pds = 1;
	unsigned long num_addrs;
	char tab_hex[] = "0123456789abcdef";
	void *addrs = va_arg(tp, void *);

	UNUSED(wa);
	UNUSED(sa);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(pa);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = tab_hex[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((ta & F_ZERO) && !(ta & F_MINUS))
		pd = '0';
	if (ta & F_PLUS)
		c = '+', length++;
	else if (ta & F_SPACE)
		c = ' ', length++;

	ind++;

	return (write_pointer(buff, ind, length,
				wa, ta, pd, c, pds));
}

/**
 * print_non_printable - Function
 * @tp: parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int print_non_printable(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	int i = 0, offset = 0;
	char *str = va_arg(tp, char *);

	UNUSED(ta);
	UNUSED(wa);
	UNUSED(pa);
	UNUSED(sa);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buff[i + offset] = str[i];
		else
			offset +=
		append_hexa_code(str[i], buff, i + offset);

		i++;
	}

	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}

/**
 * print_reverse - Function
 * @tp: Parameter
 * @buff: Parameter
 * @ta: Parameter
 * @wa: Parameter
 * @pa: Parameter
 * @sa: Parameter
 * Return: Value
 */

int print_reverse(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	char *str;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(ta);
	UNUSED(wa);
	UNUSED(sa);

	str = va_arg(tp, char *);

	if (str == NULL)
	{
		UNUSED(pa);

		str = ")NULL(";
	}
	for (i = 0; str[i]; i++)
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Function
 * @tp: Parameter
 * @buff: Parameter
 * @ta: Parameter
 * @wa: Parameter
 * @pa: Parameter
 * @sa: Parameter
 * Return: Value
 */
int print_rot13string(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxz";
	char out[] =
"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(tp, char *);
	UNUSED(buff);
	UNUSED(ta);
	UNUSED(wa);
	UNUSED(pa);
	UNUSED(sa);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

