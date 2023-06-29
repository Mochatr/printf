#include "main.h"

/**
 * print_char - function
 * @tp: parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */

int print_char(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	char c = va_arg(tp, int);

	return (handle_write_char(c, buff,
		ta, wa, pa, sa));
}

/**
 * print_string - function
 * @tp: parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int  print_string(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	int len = 0, i;
	char *str = va_arg(tp, char *);

	UNUSED(buff);
	UNUSED(ta);
	UNUSED(wa);
	UNUSED(pa);
	UNUSED(sa);
	if (str == NULL)
	{
		str = "(null)";
		if (pa >= 6)
			str = "  ";
	}

	while (str[len] != '\0')
		len++;

	if (pa >= 0 && pa <= len)
		len = pa;

	if (wa > len)
	{
		if (ta & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = wa - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (wa);
		}
	}

	return (write(1, str, len));
}

/**
 * print_percent - function
 * @tp: parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int print_percent(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	UNUSED(tp);
	UNUSED(buff);
	UNUSED(ta);
	UNUSED(wa);
	UNUSED(pa);
	UNUSED(sa);
	return (write(1, "%%", 1));
}

/**
 * print_int - Function
 * @tp: Parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int print_int(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	int i = BUFF_SIZE - 2;
	int num_neg = 0;
	long int n = va_arg(tp, long int);
	unsigned long int num;

	n = convert_size_number(n, sa);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		num_neg = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(num_neg, i,
				buff, ta, wa, pa, sa));
}

/**
 * print_binary - Function
 * @tp: Parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int print_binary(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buff);
	UNUSED(ta);
	UNUSED(wa);
	UNUSED(pa);
	UNUSED(sa);

	n = va_arg(tp, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
