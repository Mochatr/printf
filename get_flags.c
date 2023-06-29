#include "main.h"

/**
 * get_flags - Function
 * @format: Parameter
 * @i: Parameter
 * Return: Value
 */

int get_flags(const char *format, int *i)
{
	int k, j;
	int pa = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[j] == FLAGS_CH[k])
			{
				pa |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*i = j - 1;

	return (pa);
}
