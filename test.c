#include <stdio.h>

int	main (void)
{
	int	number;
	int	*ptr;

	number = printf("");
	ptr = &number;
	printf("value of empty printf: %d\n", number);
	number = 12345;
	printf(" |% +d| \n", number);
	printf(" |%010d| \n", number);
	printf(" |%-#10x| \n", number);
	printf(" |%-10x| \n", number);
	printf(" |%o| \n", number);
	printf(" |%#o| \n", number);
	printf("%p", ptr);
}
