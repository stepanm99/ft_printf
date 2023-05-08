#include "ft_printf.h"

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
	count = ft_printf("There should be a percent sign ---> %% <---\nand here should be a character: %c\n", 'Q');
	printf("\ntotal number of characters printed: %d", count);
	count = ft_printf("|\nThis is string: %s|", "|\ntest string\n|");
	printf("\ntotal number of characters printed: %d", count);
	return (0);*/

	//general test
//	size_t	n;

//	n = 3047483647;
/*	ft_printf("12345\n");
	ft_printf("chnaracter: |%c|\n", 'c');
	ft_printf("string: |%s|\n", "test");
	ft_printf("pointer: |%p|\n", &count);
	ft_printf("integer: |%i|\n", -42);
	ft_printf("decimal: |%d|\n", 42);
	ft_printf("unsigned: |%u|\n", n);
	ft_printf("hex low: |%#x|\n", 125);
	printf("hex low: |%#x|\n", 125);
	ft_printf("hex up: |%#X|\n", 125);
	ft_printf("percent: |%%|\n");*/
	ft_printf("with flag: |%12d|\n", 256);

/*	printf("this is pointer: |%p|\n", &n);
	ft_printf("this should be same thing |%p|\n", &n);

	count = ft_printf("This is number: %d\n", 120);
	printf("number of printed characters: %d\n", count);*/
	return (0);
}
