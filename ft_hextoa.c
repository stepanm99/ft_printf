/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:44:15 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/10 23:44:21 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getlen(size_t n);
static int	getdigit(size_t n, char *ptr, int l, t_data *data);

char	*ft_hextoa(size_t n, t_data *data)
{
	int		l;
	char	*ptr;

	l = getlen(n);
	ptr = ft_calloc(l + 1, sizeof(char));
	if (!ptr)
		return (0);
	getdigit(n, ptr, l, data);
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
		n = n / 16;
		len++;
	}
	return (len);
}

static int	getdigit(size_t n, char *ptr, int l, t_data *data)
{
	int	mod;

	if (n == 0)
		ptr[0] = '0';
	ptr[l] = '\0';
	while (n > 0)
	{
		mod = n % 16;
		if (mod < 10)
			ptr[l - 1] = mod + '0';
		else
		{
			if (data->hexup)
				ptr[l - 1] = (mod - 10) + 'A';
			else
				ptr[l - 1] = (mod - 10) + 'a';
		}
		n = n / 16;
		l--;
	}
	return (0);
}
