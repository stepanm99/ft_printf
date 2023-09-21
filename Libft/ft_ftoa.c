/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:43:49 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/21 22:13:56 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static unsigned long	ft_dec_pow(int x)
{
	unsigned long	res;

	res = 1;
	while (x >= 0)
	{
		res = res * 10;
		x--;
	}
	return (res);
}

static int	getlen(double n, int prec)
{
	int		len;
	int		before_point;

	len = 0;
	before_point = (int)n;
	if (before_point == 0)
		return (1);
	while (before_point)
	{
		before_point = before_point / 10;
		len++;
	}
	return (len + prec + 1);
}

/*
static int	getdigit(int n, char *ptr, int neg, int l)
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
*/

static void	getdigit(double n, char *ptr, int neg, int l, int prec)
{
	int		i;
	int		before_point;
	double	after_point;

	i = 0;
	before_point = (int)n;
	after_point = n - before_point;
	while (before_point)
	{
		ptr[i] = (before_point % 10) + '0';
		before_point = before_point / 10;
		i++;
	}
	ptr[i] = '.';
	i++;
	before_point = after_point * ft_dec_pow(prec);
	while (l >= i)
	{
		ptr[l] = (before_point % 10) + '0';
		before_point = before_point / 10;
		l--;
	}
}

char	*ft_ftoa(double n, int prec)
{
	int		l;
	char	*ptr;
	int		neg;

	ptr = NULL;
	if (prec > 10)
		prec = 10;
	prec--;
	neg = 0;
	if (n < 0)
	{
		n = (n * (-1));
		neg = 1;
	}
	l = getlen(n, prec);
	if (neg)
		l++;
	ptr = ft_calloc((l + 2), sizeof(char));
	if (!ptr)
		return (0);
	getdigit(n, ptr, neg, l, prec);
	return (ptr);
}
