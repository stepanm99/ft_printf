/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:09:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/29 20:11:24 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numl(int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static void	prec(t_data *data)
{
	if (data->varl > data->prec)
		return ;
	else
		data->prec = data->prec - data->varl;
	while (data->prec != 0)
	{
		write(1, "0", 1);
		data->counter++;
		data->prec--;
	}
}

static long	check_neg(t_data *data, long n)
{
	if ((n < 0 && data->dot && (n != -2147483648)) && data->padnum == 0)
	{
		n = n * (-1);
		data->decneg = 1;
		write(1, "-", 1);
		data->counter++;
		data->varl++;
		data->prec++;
	}
	else if (n < 0 && !data->dot && (data->padnum > numl(n))
		&& (n != -2147483648) && (n > -2147483648) && !data->zero)
		return (n);
	else if (n < 0 && !data->dot && data->padnum && (n != -2147483648)
		&& (n > -2147483648) && !data->space)
	{
		n = n * (-1);
		data->decneg = 1;
		write(1, "-", 1);
		data->counter++;
		data->padnum--;
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
	data->varl += ft_strlen(string);
	plus_pad_resolve(data, string);
	prec(data);
	if ((*string == '-' && !data->dash) || (*string == '-' && data->decneg))
		string++;
	while (*string != '\0')
	{
		write(1, string, 1);
		data->counter++;
		string++;
	}
	if (data->padnum && data->dash)
		ft_print_pad_dec(data, string);
	free(ptr);
	return (0);
}

void	ft_print_pad_dec(t_data *data, char *string)
{
	char	c;

	if (data->zero && !data->dash)
		c = '0';
	else
		c = ' ';
	padnum_precision_decimal_edit(data, string);
	while (data->padnum != 0)
	{
		write(1, &c, 1);
		data->counter++;
		data->padnum--;
	}
}
