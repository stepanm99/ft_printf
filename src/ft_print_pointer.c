/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:27 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/19 17:44:22 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static int	getlen(unsigned long n)
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

static int	getdigit(unsigned long n, char *ptr, int l, t_data *data)
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

static char	*ft_ptoa(unsigned long n, t_data *data)
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

int	ft_print_pointer(t_data *data)
{
	char	*string;
	char	*ptr;

	string = ft_ptoa(va_arg(*data->args, unsigned long), data);
	ptr = string;
	write(1, "0x", 2);
	data->counter += 2;
	while (*string != '\0')
	{
		write(1, string, 1);
		data->counter++;
		string++;
	}
	free(ptr);
	return (0);
}
