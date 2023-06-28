#include "main.h"

/**
 * get_precision - Function that calculates precision for printing.
 * @format: Argument
 * @i: Input
 * @list: Parameter
 *
 * Return: the precision for printing
 */
int get_precision(const char *format, int *i, va_list list)
{
	int Curr = *i + 1;
	int Precision = -1;

	if (format[Curr] != '.')
	{
		return (Precision);
	}

	Precision = 0;

	for (Curr += 1; format[Curr] != '\0'; Curr++)
	{
		if (is_digit(format[Curr]))
		{
			Curr++;
			Precision = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = Curr - 1;

	return (Precision);
}
