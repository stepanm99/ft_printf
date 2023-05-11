#include "ft_printf.h"
#include <limits.h>

void	check_leaks();

int	main(void)
{
	int	count_my;
	int	count_og;

	count_my = 0;
	count_og = 0;
	printf("--------------------------\n");
	count_my = ft_printf(" %-3d ", 1);
	printf("\n--------------------------\n");
	count_og = printf(" %-3d ", 1);
	printf("\n--------------------------\n");
	printf("RETURNS:\nmy function:\t%i\nog function:\t%i\n", count_my, count_og);
	printf("\n--------------------------\n");
	check_leaks();
	return (0);
}
