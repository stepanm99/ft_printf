/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:09:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/26 23:13:40 by smelicha         ###   ########.fr       */
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

static void	padnum_precision_edit(t_data *data, char *string)
{
	if (!data->dot && (data->padnum - data->varl) >= 0)
	{
		data->padnum = data->padnum - data->varl;
		if (data->space && !ft_char_comp('-', string))
			data->padnum--;
	}
	else if (!data->dot && (data->padnum - data->varl) < 0)
		data->padnum = 0;
	else if ((data->prec > data->padnum && (data->padnum - data->varl) >= 0) && data->dot)
		data->padnum = 0;
	else if ((data->padnum > data->varl && data->varl > data->prec) && data->dot)
		data->padnum = data->padnum - data->varl;
	else if ((data->padnum > data->varl && data->varl <= data->prec) && data->dot)
		data->padnum = data->padnum - data->prec;
	else if (data->padnum > data->prec && data->prec < data->varl && data->dot)
		data->padnum = 0;
	else if (((data->prec < data->padnum) && data->padnum < data->varl) && data->dot)
		data->padnum = data->padnum - data->prec;
	else if ((data->prec >= data->padnum && (data->padnum - data->varl) < 0) && data->dot)
		data->padnum = 0;


	if ((data->prec > data->padnum) && data->space && data->dot && !ft_char_comp('-', string) && data->padnum)
	{
		data->varl--;
		data->padnum--;
	}
	else if ((data->prec > data->padnum) && data->space && data->dot && !ft_char_comp('-', string) && (data->padnum == 0))
		data->prec++;
	else if ((data->prec <= data->padnum) && data->space && data->dot && !ft_char_comp('-', string))
	{
		data->prec++;
		data->padnum--;
	}
	else if (data->dot && data->space && (data->padnum > data->prec) && (data->prec >= data->varl))
		data->padnum--;
}

static void	ft_print_pad_dec(t_data *data, char *string)
{
	char	c;

	if (data->zero && !data->dash)
		c = '0';
	else
		c = ' ';
	padnum_precision_edit(data, string);
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
	/*if (!ft_char_comp('-', string) && !((*string == '0') && data->varl == 1) && data->space)
	{
		write(1, " ", 1);
		data->counter++;
		data->varl++;
	}*/
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
	if ((((ft_char_comp('-', string) && !data->dash) && !data->dot) && data->padnum < data->varl) && data->decneg)
	{
		write(1, "-", 1);
		data->counter++;
	}
	if ((((ft_char_comp('-', string) && !data->dash) && data->dot) && data->padnum > 0)
		&& (data->prec > data->padnum || data->prec > data->varl))
		data->padnum--;
	if (data->padnum && !data->dash)
		ft_print_pad_dec(data, string);
	if (((ft_char_comp('-', string) && !data->dash) && !data->dot))
	{
		write(1, "-", 1);
		data->counter++;
	}
	if (ft_char_comp('-', string) && !data->dash && data->dot)
	{
		write(1, "-", 1);
		data->counter++;
		data->prec++;
	}
	if (!data->dash)
		plus_space(data, string);
}

static void	prec(t_data *data)
{
	if (data->varl > data->prec)
		return ;
	else
		data->prec = data->prec - data->varl;
//	if (data->space)
//		data->prec++;
	while (data->prec !=0)
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
	else if (n < 0 && !data->dot && (data->padnum > numl(n)) && (n != -2147483648) && (n > -2147483648) && !data->zero)
		return (n);
	else if (n < 0 && !data->dot && data->padnum && (n != -2147483648) && (n > -2147483648))
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
	long		n;

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
