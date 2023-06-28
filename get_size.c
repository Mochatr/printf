#include "main.h"

/**
 * get_size - calculates the size
 * in order to cast argument
 * @format: Argument
 * @i: Argument
 *
 * Return: precision
 */

int get_size(const char *format, int *i)
{
	int Curr = *i + 1;
	int Size = 0;

	if (format[Curr] == 'l')
	{
		Size = S_LONG;
	}
	else if (format[Curr] == 'h')
	{
		Size = S_SHORT;
	}
	if (Size == 0)
	{
		*i = Curr - 1;
	}
	else
	{
		*i = Curr;
	}
	return (size);
}

