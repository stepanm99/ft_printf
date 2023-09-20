/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:09:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/19 18:03:14 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static long	check_neg(t_data *data, long n)
{
	if (n < 0)
	{
		n = n * (-1);
		data->decneg = 1;
		write(1, "-", 1);
		data->counter++;
	}
	return (n);
}

int	ft_print_decimal(t_data *data)
{
	char	*string;
	char	*ptr;
	long	n;

	n = check_neg(data, va_arg(*data->args, int));
	string = ft_itoa(n);
	ptr = string;
	if ((*string == '-') || (*string == '-' && data->decneg))
		string++;
	while (*string != '\0')
	{
		write(1, string, 1);
		data->counter++;
		string++;
	}
	free(ptr);
	return (0);
}
