#include "libftprintf.h"
#include "Libft/libft.h"

int	main(void)
{
//	char	test[] = "\n\ttext from the variable\n";
//	printf("return value: %d\n\n", ft_printf("test of the string %qjkjsld\nnext %d line\n\0"));
	struct s_flags	test;

	test = ft_flaginit();
	printf("value of left %d\n", test.left);
	printf("value of zero %d\n", test.zero);
	printf("value of space %d\n", test.space);
	printf("value of hash %d\n", test.hash);
	printf("value of plus %d\n", test.plus);
	return (0);
}
