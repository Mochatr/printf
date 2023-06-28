#include "main.h"

/**
 * handle_write_char - Function
 * @c: Parameter
 * @buff: Parameter
 * @ta:  Parameter
 * @wa: Parameter
 * @pa: Parameter
 * @sa: Parameter
 *
 * Return: Value
 */

int handle_write_char(char c, char buff[],
	int ta, int wa, int pa, int sa)
{
	int k = 0;
	char pd = ' ';

	UNUSED(pa);
	UNUSED(sa);

	if (ta & F_ZERO)
		pd = '0';

	buff[k++] = c;
	buff[k] = '\0';

	if (wa > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (k = 0; k < wa - 1; k++)
			buff[BUFF_SIZE - k - 2] = pd;

		if (ta & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - k - 1], wa - 1));
		else
			return (write(1, &buff[BUFF_SIZE - k - 1], wa - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/**
 * write_number - Function
 * @num_neg: Parameter
 * @i: Parameter
 * @buff: Parameter
 * @ta:  Parameter
 * @wa: Parameter
 * @pa: Parameter
 * @sa: Parameter
 *
 * Return: Value
 */

int write_number(int num_neg, int i, char buff[],
	int ta, int wa, int pa, int sa)
{
	int len = BUFF_SIZE - i - 1;
	char pd = ' ', c = 0;

	UNUSED(sa);

	if ((ta & F_ZERO) && !(ta & F_MINUS))
		pd = '0';
	if (num_neg)
		c = '-';
	else if (ta & F_PLUS)
		c = '+';
	else if (ta & F_SPACE)
		c = ' ';

	return (write_num(i, buff, ta, wa, pa,
		len, pd, c));
}

/**
 * write_num - Function
 * @i: Parameter
 * @buff: Parameter
 * @ta: Parameter
 * @wa: Parameter
 * @pa: Parameter
 * @len: Parameter
 * @pd: Parameter
 * @c: Parameter
 *
 * Return: Value
 */

int write_num(int i, char buff[],
	int ta, int wa, int pa,
	int len, char pd, char c)
{
	int k, pds = 1;

	if (pa == 0 && i == BUFF_SIZE - 2 && buff[i] == '0' && wa == 0)
		return (0);
	if (pa == 0 && i == BUFF_SIZE - 2 && buff[i] == '0')
		buff[i] = pd = ' ';
	if (pa > 0 && pa < len)
		pd = ' ';
	while (pa > len)
		buff[--i] = '0', len++;
	if (c != 0)
		len++;
	if (wa > len)
	{
		for (k = 1; k < wa - len + 1; k++)
			buff[k] = pd;
		buff[k] = '\0';
		if (ta & F_MINUS && pd == ' ')
		{
			if (c)
				buff[--i] = c;
			return (write(1, &buff[i], len) + write(1, &buff[1], k - 1));
		}
		else if (!(ta & F_MINUS) && pd == ' ')
		{
			if (c)
				buff[--i] = c;
			return (write(1, &buff[1], k - 1) + write(1, &buff[i], len));
		}
		else if (!(ta & F_MINUS) && pd == '0')
		{
			if (c)
				buff[--pds] = c;
			return (write(1, &buff[pds], k - pds) +
				write(1, &buff[i], len - (1 - pds)));
		}
	}
	if (c)
		buff[--i] = c;
	return (write(1, &buff[i], len));
}

/**
 * write_unsgnd - Function
 * @num_neg: Parameter
 * @i: Parameter
 * @buff: Parameter
 * @ta: Parameter
 * @wa: Parameter
 * @pa: Parameter
 * @sa: Parameter
 *
 * Return: Value
 */

int write_unsgnd(int num_neg, int i,
	char buff[],
	int ta, int wa, int pa, int sa)
{
	int len = BUFF_SIZE - i - 1, k = 0;
	char pd = ' ';

	UNUSED(num_neg);
	UNUSED(sa);

	if (pa == 0 && i == BUFF_SIZE - 2 && buff[i] == '0')
		return (0);

	if (pa > 0 && pa < len)
		pd = ' ';

	while (pa > len)
	{
		buff[--i] = '0';
		len++;
	}

	if ((ta & F_ZERO) && !(ta & F_MINUS))
		pd = '0';

	if (wa > len)
	{
		for (k = 0; k < wa - len; k++)
			buff[k] = pd;

		buff[k] = '\0';

		if (ta & F_MINUS)
		{
			return (write(1, &buff[i], len) + write(1, &buff[0], k));
		}
		else
		{
			return (write(1, &buff[0], k) + write(1, &buff[i], len));
		}
	}

	return (write(1, &buff[i], len));
}


/**
 * write_pointer - Function
 * @buff: Parameter
 * @i: Parameter
 * @len: Parameter
 * @wa: Parameter
 * @ta: Paremeter
 * @pd: Parameter
 * @c: Parameter
 * @pds: Parameter
 *
 * Return: Value
 */

int write_pointer(char buff[], int i, int len,
	int wa, int ta, char pd, char c, int pds)
{
	int k;

	if (wa > len)
	{
		for (k = 3; k < wa - len + 3; k++)
			buff[k] = pd;
		buff[k] = '\0';
		if (ta & F_MINUS && pd == ' ')
		{
			buff[--i] = 'x';
			buff[--i] = '0';
			if (c)
				buff[--i] = c;
			return (write(1, &buff[i], len) + write(1, &buff[3], k - 3));
		}
		else if (!(ta & F_MINUS) && pd == ' ')
		{
			buff[--i] = 'x';
			buff[--i] = '0';
			if (c)
				buff[--i] = c;
			return (write(1, &buff[3], k - 3) + write(1, &buff[i], len));
		}
		else if (!(ta & F_MINUS) && pd == '0')
		{
			if (c)
				buff[--pds] = c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[pds], k - pds) +
				write(1, &buff[i], len - (1 - pds) - 2));
		}
	}
	buff[--i] = 'x';
	buff[--i] = '0';
	if (c)
		buff[--i] = c;
	return (write(1, &buff[i], BUFF_SIZE - i - 1));
}
