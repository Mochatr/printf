#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - It prints a function
 * @format: Parameter
 *
 * Return: Printed characters
 */
int _printf(const char *format, ...)
{
	int a, Printed = 0;
	int characters_printed = 0;
	int Flags, Width, Precision, Size, Buff_ind = 0;
	va_list List;
	char BUFFER[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_Start(List, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			BUFFER[buff_ind++] = format[a];
			if (butt_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
			characters_printed++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			Flags = get_flags(format, &a);
			Width = get_width(format, &a, List);
			Precision = get_precision(format, &a, List);
			Size = get_size(format, &a);
			++a;
			Printed = handle_print(format, &a, List,
				BUFFER, Flags, Width, Precision, Size);
			if (Printed == -1)
				return (-1);
			characters_printed += Printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_End(List);
	return (characters_printed);
}
/**
 * print_buffer - Function that prints the content of the buffer
 * if it does exist
 * @buffer: Parameter
 * @buff_ind: Argument
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}



