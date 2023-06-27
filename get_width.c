#include "main.h"

int get_width(const char *format, int *i, va_list va)
{
	int k;
	int w = 0;

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		if (is_digit(format[k]))
		{
			w *= 10;
			w += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			w = va_arg(va, int);
			break;
		}
		else
			break;
	}

	*i = k - 1;

	return (w);
}
