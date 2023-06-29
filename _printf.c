#include "main.h"

void print_buffer(char buff[], int *bfd);

/**
 * _printf - Function
 * @format: parameter
 * Return: Value
 */

int _printf(const char *format, ...)
{
	int k, printed = 0, ptc = 0;
	int ta, wa, pa, sa, bfd = 0;
	va_list va;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(va, format);

	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buff[bfd++] = format[k];
			if (bfd == BUFF_SIZE)
				print_buffer(buff, &bfd);
			ptc++;
		}
		else
		{
			print_buffer(buff, &bfd);
			ta = get_flags(format, &k);
			wa = get_width(format, &k, va);
			pa = get_precision(format, &k, va);
			sa = get_size(format, &k);
			++k;
			printed = handle_print(format, &k, va, buff, ta, wa, pa, sa);
			if (printed == -1)
				return (-1);
			ptc += printed;
		}
	}

	print_buffer(buff, &bfd);

	va_end(va);

	return (ptc);
}

/**
 * print_buffer - Function
 * @buff: Parameter
 * @bfd: Parameter
 */

void print_buffer(char buff[], int *bfd)
{
	if (*bfd > 0)
		write(1, &buff[0], *bfd);
	*bfd = 0;
}

