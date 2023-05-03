#include "libftprintf.h"
#include "Libft/libft.h"

int	main(void)
{
//	char	test[] = "\n\ttext from the variable\n";
//	printf("return value: %d\n\n", ft_printf("test of the string %qjkjsld\nnext %d line\n\0"));
	struct s_flags	test;
	int		count;

	test = ft_flaginit();
	printf("value of left %d\n", test.dash);
	printf("value of zero %d\n", test.zero);
	printf("value of space %d\n", test.space);
	printf("value of hash %d\n", test.hash);
	printf("value of plus %d\n", test.plus);
	count = ft_printf("There should be a percent sign ---> %% <---\n");
	printf("\ntotal number of characters printed: %d", count);
	printf("\ntotal number of characters printed: %d", count);
	return (0);
}
