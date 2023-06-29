#include "main.h"

/**
 * get_precision - Function
 * @format: Parameter
 * @i: Parameter
 * @va: Parameter
 *
 * Return: Value
 */
int get_precision(const char *format, int *i,
		va_list va)
{
	int k = *i + 1;
	int pr = -1;

	if (format[k] != '.')
		return (pr);

	pr = 0;

	for (k += 1; format[k] != '\0'; k++)
	{
		if (is_digit(format[k]))
		{
			pr *= 10;
			pr += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			pr = va_arg(va, int);
			break;
		}
		else
			break;
	}

	*i = k - 1;

	return (pr);
}
