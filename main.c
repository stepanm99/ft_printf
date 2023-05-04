#include "libftprintf.h"
#include "Libft/libft.h"

int	main(void)
{
//	char	data[] = "\n\ttext from the variable\n";
//	printf("return value: %d\n\n", ft_printf("data of the string %qjkjsld\nnext %d line\n\0"));
//	int		count;
/*
	data = ft_datainit();
	printf("value of left %d\n", data.dash);
	printf("value of zero %d\n", data.zero);
	printf("value of space %d\n", data.space);
	printf("value of hash %d\n", data.hash);
	printf("value of plus %d\n", data.plus);
//	count = ft_printf("There should be a percent sign ---> %% <---\nand here should be a character: %c\n", 'Q');
//	printf("\ntotal number of characters printed: %d", count);
	count = ft_printf("|\nThis is string: %s|", "|\ntest string\n|");
	printf("\ntotal number of characters printed: %d", count);
	return (0);*/

	char	test[] = "abcd";
	char	test1[] = "bcde";
	char	c1 = 'a';
	char	c2 = 'c';
	int		res = 0;

	res = ft_char_comp(c1, test);
	printf("%d\n", res);
	res = ft_char_comp(c1, test1);
	printf("%d\n", res);
	res = ft_char_comp(c2, test);
	printf("%d\n", res);
}
