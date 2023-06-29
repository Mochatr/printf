#include "main.h"

/**
 * get_size - Function
 * @format: Parameter
 * @i: Parameter
 *
 * Return: Value
 */
int get_size(const char *format, int *i)
{
	int k = *i + 1;
	int sz = 0;

	if (format[k] == 'l')
		sz = S_LONG;
	else if (format[k] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*i = k - 1;
	else
		*i = k;

	return (sz);
}
