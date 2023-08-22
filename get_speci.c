#include "main.h"

/**
 * get_speci - find func
 * @s: character string
 * Return: a number of bytes
 */
int (*get_speci(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'x', print_hex},
		{'i', print_int},
		{'s', print_string},
		{'X', print_HEX},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'S', print_S},
		{'p', print_address},
		{'%', print_percent},
		{'r', print_rev},
		{NULL, NULL}
		};
	int flags = 14;
	int i = 0;

	for (; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
