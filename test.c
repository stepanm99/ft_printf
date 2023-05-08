#include<stdio.h>

int	main(void)
{
	int	n;
	int	*ptr;

	n = 9;
	ptr = &n;
	printf("this is pointer: %lu\n", ptr);
	return (0);
}