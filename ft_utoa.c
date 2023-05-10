/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:52:33 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/10 23:52:37 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getlen(size_t n);
static int	getdigit(size_t n, char *ptr, int l);

char	*ft_utoa(size_t n)
{
	int		l;
	char	*ptr;

	l = getlen(n);
	ptr = ft_calloc(l + 1, sizeof(char));
	if (!ptr)
		return (0);
	getdigit(n, ptr, l);
	return (ptr);
}

static int	getlen(size_t n)
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

static int	getdigit(size_t n, char *ptr, int l)
{
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
