#include "main.h"

/**
 * handle_write_char - Function
 * @format: Parameter
 * @buff: Parameter
 * @ks:  Parameter
 * @ma: Parameter
 * @sap: Parameter
 * @bt: Parameter
 * @va: Parameter
 * @a: Parameter
 *
 * Return: Value
 */

int handle_print(const char *format, int *a, va_list va, char buff[],
	int ks, int ma, int sap, int bt)
{
	int i, var = 0, pta = -1;
	format_tp format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*a] == format_types[i].format)
			return (format_types[i].fn(va, buff, ks, ma, sap, bt));

	if (format_types[i].format == '\0')
	{
		if (format[*a] == '\0')
			return (-1);
		var += write(1, "%%", 1);
		if (format[*a - 1] == ' ')
			var += write(1, " ", 1);
		else if (ma)
		{
			--(*a);
			while (format[*a] != ' ' && format[*a] != '%')
				--(*a);
			if (format[*a] == ' ')
				--(*a);
			return (1);
		}
		var += write(1, &format[*a], 1);
		return (var);
	}
	return (pta);
}
