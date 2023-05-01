#include "libftprintf.h"

int	main(void)
{
	char	test[] = "\n\ttext from the variable\n";
	ft_print("test of the string %qjkjsld\nnext %d line\n\0", test, 125);
	return (0);
}
