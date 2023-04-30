#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_print(const char *fmt, ...)
{
	va_list	args;

	va_start (args, fmt);
	while (fmt)
	{
		while (*fmt != '\0')
		{
			write(1, fmt, 1);
			fmt++;;
		}
	}
	va_end (args);
	return (0);
}

int	main(void)
{
	char	nr1[] = "test1\n";
	char	nr2[] = "test2\n";
	char	nr3[] = "12345";
	ft_print(nr1, nr2, nr3);
	return (0);
}
