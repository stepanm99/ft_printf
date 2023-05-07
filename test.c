#include"Libft/libft.h"
#include <stdio.h>

static int	getlen(unsigned long int n);
static int	getdigit(unsigned long n, char *ptr, int neg, int l);
static char	*edge(void);

char	*ft_utoa(unsigned long int n)
{
	int		l;
	char	*ptr;
	int		neg;
	size_t	i;

	neg = 0;
	i = 0;
	l = getlen(n);
	if (neg)
		l++;
	ptr = ft_calloc(l + 1, sizeof(char));
	if (!ptr)
		return (0);
	getdigit(n, ptr, neg, l);
	return (ptr);
}

static int	getlen(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	getdigit(unsigned long int n, char *ptr, int neg, int l)
{
	size_t	i;

	i = 0;
	if (neg)
	{
		ptr[0] = '-';
	}
	if (n == 0)
		ptr[0] = '0';
	ptr[l] = '\0';
	while (n > 0)
	{
		ptr[l - 1] = ((n % 10) + '0');
		n = n / 10;
		l--;
	}
	return (0);
}

int	main(void)
{
	char			*test;
	unsigned long int	n;
	int					n2;

	n = 4294967000;
	n2 = 50;
	test = ft_utoa(n);
	printf("string: %s\n", test);
	test = ft_utoa(n2);
	printf("string: %s\n", test);
	printf("test of %%d with floating point number: %d\n", 10.42);
	return (0);
}
