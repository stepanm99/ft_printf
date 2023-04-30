#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

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
				int	nbr = va_arg(args, int);
				char	*nbra = ft_itoa(nbr);
				while (*nbra != '\0')
				{
					write(1, nbra, 1);
					nbra++;
				}
			}
		}
		fmt++;
	}
	va_end (args);
	return (0);
}

int	main(void)
{
	char	test[] = "\n\ttext from the variable\n";
	ft_print("test of the string %qjkjsld\nnext %d line\n\0", test, 125);
	return (0);
}
