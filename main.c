#include "libftprintf.h"
#include "Libft/libft.h"
#include <stdio.h>

int	main(void)
{
//	char	test[] = "\n\ttext from the variable\n";
	printf("return value: %d\n\n", ft_printf("test of the string %qjkjsld\nnext %d line\n\0"));
	return (0);
}
