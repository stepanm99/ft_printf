#include "src/ft_printf.h"
#include <limits.h>

//void	check_leaks();

int	main(void)
{
	int		count_my;
	int		count_og;
	long	i;

	count_my = 0;
	count_og = 0;
	i = 0;
	printf("--------------------------\n");
	count_my = ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n--------------------------\n");
	count_og = printf(" %u %u %lu %lu %lu %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n--------------------------\n");
	printf("RETURNS:\nmy function:\t%i\nog function:\t%i\n", count_my, count_og);
	printf("\n--------------------------\n");

	// printf("--------------------------\n");
	// count_my = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf("\n--------------------------\n");
	// count_og = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf("\n--------------------------\n");
	// printf("RETURNS:\nmy function:\t%i\nog function:\t%i\n", count_my, count_og);
	// printf("\n--------------------------\n");

	// printf("--------------------------\n");
	// count_my = ft_printf(" |% -5d| ", 1);
	// printf("\n--------------------------\n");
	// count_og = printf(" |% -5d| ", 1);
	// printf("\n--------------------------\n");
	// printf("RETURNS:\nmy function:\t%i\nog function:\t%i\n", count_my, count_og);
	// printf("\n--------------------------\n");

	// printf("--------------------------\n");
	// count_my = ft_printf(" |%-5d| ", -15);
	// printf("\n--------------------------\n");
	// count_og = printf(" |%-5d| ", -15);
	// printf("\n--------------------------\n");
	// printf("RETURNS:\nmy function:\t%i\nog function:\t%i\n", count_my, count_og);
	// printf("\n--------------------------\n");

	printf("--------------------------\n");
	count_my = ft_printf("hxx?$X%cqf2\n;U%d&XWTH#%u`D8VK) As%%AXEKPc@w$%u%um#*%u", -736244248, 1459274746, 1497298676, -30071924, 1958771183, -785266128);
	printf("\n--------------------------\n");
	count_og = printf("hxx?$X%cqf2\n;U%d&XWTH#%u`D8VK) As%%AXEKPc@w$%u%um#*%u", -736244248, 1459274746, 1497298676, -30071924, 1958771183, -785266128);
	printf("\n--------------------------\n");
	printf("RETURNS:\nmy function:\t%i\nog function:\t%i\n", count_my, count_og);
	printf("\n--------------------------\n");
//	check_leaks();
	printf("--------------------------\n");
	count_my = ft_printf("%23s", NULL);
	printf("\n--------------------------\n");
	count_og = printf("%23s", NULL);
	printf("\n--------------------------\n");
	printf("RETURNS:\nmy function:\t%i\nog function:\t%i\n", count_my, count_og);
	printf("\n--------------------------\n");
	return (0);
}
