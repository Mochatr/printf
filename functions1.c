#include "main.h"

/**
 * print_unsigned - Function
 * @tp: parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int print_unsigned(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(tp, unsigned long int);

	num = convert_size_unsgnd(num, sa);

	if (num  == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buff, ta,
				wa, pa, sa));
}

/**
 * print_octal - Function
 * @tp: parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int print_octal(va_list tp, char buff[],
		int ta, int wa, int pa, int sa)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(tp, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wa);

	num = convert_size_unsgnd(num, sa);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (ta & F_HASH && init_num != 0)
		buff[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buff, ta, wa, pa, sa));
}

/**
 * print_hexadecimal - function
 * @tp: parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int print_hexadecimal(va_list tp, char buff[],
		int ta, int wa, int pa, int sa);
{
	return (print_hexa(tp, "0123456789abcdef", buff,
				ta, 'x', wa, pa, sa));
}

/**
 * print_hexa_upper - function
 * @tp: parameter
 * @buff: parameter
 * @ta: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int print_hexa_upper(va_list tp, char buff[],
		int ta, int wa, int int pa, int sa)
{
	return (print_hexa(tp, "0123456789ABCDEF", buff, ta, 'X', wa, pa, sa));
}

/**
 * print_hexa - function
 * @tp: parameter
 * @tab_hex: parameter
 * @buff: parameter
 * @ta: parameter
 * @flag_ch: parameter
 * @wa: parameter
 * @pa: parameter
 * @sa: parameter
 * Return: Value
 */
int print_hexa(va_list tp, char tab_hex[],
		char buff[], int ta, char flag_ch, int wa,
		int pa, int sa)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(tp, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wa);

	num = convert_size_unsgnd(num, sa);
	if (num == 0)
		buff[i--] = '\0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = tab_hex[num % 16];
		num /= 16;
	}

	if (ta & F_HASH && init_num != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buff, ta, wa, pa, sa));
}

