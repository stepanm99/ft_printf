#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_print(const char *fmt, ...)
{
	va_list	args;
	va_start(args, fmt);

	return (0);
}

int	main()
{
	ft_print("test", of, this, thing);
	return(0);
}
