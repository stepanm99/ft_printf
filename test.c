#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

int	ft_print(const char *fmt, ...)
{
	va_list	args;

	va_start (args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			write(1, fmt, 1);
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'q')
			{
				char	*test = va_arg(args, char *);
				while (*test != '\0')
				{
					write(1, test, 1);
					test++;
				}
			}
			if (*fmt == 'd')
			{
				printf("\ntest decimal\n");
			}
		}
		fmt++;
	}
	va_end (args);
	return (0);
}
