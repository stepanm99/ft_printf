/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:09:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/24 19:49:29 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	padnum_precision_edit(t_data *data)
{
	if ((((data->padnum > data->varl) || ((data->padnum > data->prec
			|| (data->prec > data->varl)))) && (data->prec != 0))
			&& data->dot && (data->padnum > data->prec))
		data->padnum = data->padnum - data->prec;
	else if (((data->padnum > data->varl) && (data->prec > data->varl)) && data->dot)
		data->padnum = data->padnum - data->varl;
	else if ((data->padnum > data->varl) && !data->dot)
		data->padnum = data->padnum - data->varl;
	else if (data->pre && !((data->varl > data->prec) || (data->padnum < data->pre)))
		data->padnum = data->padnum - data->pre;
	else if (((data->padnum > data->pre && data->varl > data->pre) && data->dot) && data->pre)
		data->padnum = data->padnum - data->pre;
	else
		data->padnum = 0;
}

static void	ft_print_pad_dec(t_data *data)
{
	char	c;

	if (data->zero && !data->dash)
		c = '0';
	else
		c = ' ';
	padnum_precision_edit(data);
	while (data->padnum != 0)
	{
		write(1, &c, 1);
		data->counter++;
		data->padnum--;
	}
}

static void	plus_space(t_data *data, char *string)
{
	if ((ft_char_comp('-', string)) && data->plusspace)
	{
		data->plusspace = 0;
	}
	if (!ft_char_comp('-', string) && data->plus)
	{
		write(1, "+", 1);
		data->counter++;
		data->varl++;
	}
	if (!ft_char_comp('-', string) && data->space)
	{
		write(1, " ", 1);
		data->counter++;
		data->varl++;
	}
}

static void	plus_pad_resolve(t_data *data, char *string)
{
	if (data->dash)
		plus_space(data, string);
	if (ft_char_comp('-', string) && !data->dash)
	{
		write(1, "-", 1);
		data->counter++;
	}
	if (data->padnum && !data->dash)
		ft_print_pad_dec(data);
	if (!data->dash)
		plus_space(data, string);
}

static void	prec(t_data *data)
{
	if (data->varl > data->prec)
		return ;
	else
		data->prec = data->prec - data->varl;
	while (data->prec !=0)
	{
		write(1, "0", 1);
		data->counter++;
		data->prec--;
	}
}

static int	check_neg(t_data *data, int n)
{
	if ((n < 0 && data->dot && (n != -2147483648)))
	{
		n = n * (-1);
		write(1, "-", 1);
		data->counter++;
	}
	return (n);
}

int	ft_print_decimal(t_data *data)
{
	char	*string;
	char	*ptr;
	int		n;

	n = check_neg(data, va_arg(*data->args, int));
	string = ft_itoa(n);
	ptr = string;
	data->varl = ft_strlen(string);
	plus_pad_resolve(data, string);
	prec(data);
	if (*string == '-' && !data->dash)
		string++;
	while (*string != '\0')
	{
		write(1, string, 1);
		data->counter++;
		string++;
	}
	if (data->padnum && data->dash)
		ft_print_pad_dec(data);
	free(ptr);
	return (0);
}
