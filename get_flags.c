#include "main.h"

/**
 * get_flags - Function
 * @format: Parameter
 * @i: Parameter
 * Return: Value
 */

int get_flags(const char *format, int *i)
{
	int i, j;
	int pa = 0;
	const char arrith[] = {'-', '+', '0', '#', ' ', '\0'};
	const int arrith_sym[] = {AR_MINUS, AR_PLUS, AR_ZERO, AR_HASH, AR_SPACE, 0};

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		for (i = 0; arrith[i] != '\0'; i++)
			if (format[j] == arrith[i])
			{
				pa |= arrith_sym[i];
				break;
			}

		if (arrith[i] == 0)
			break;
	}

	*i = j - 1;

	return (pa);
}

