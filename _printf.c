#include "main.h"
#include <limits.h>
/**
 * _printf - create output after formatting
 * @format: the formated data
 * Description: data is converted using functions in this project
 * Return: the length of output
 */
 
int _printf(const char *format, ...)
{	int (*prfun)(va_list, flags_t *);
	const char *p;
	flags_t flags = {0, 0, 0};
	int coun = 0;

	va_start(argum, format);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				coun += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			prfun = get_print(*p);
			coun += (prfun)
				? prfun(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			coun += _putchar(*p);
	}
	_putchar(-1);
	va_end(argum);
	return (coun);
}
