/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:52:48 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/29 20:10:53 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (!((*string == '0') && data->varl == 1) && ((data->counter > 2)))
			data->varl++;
	}
}

static void	padnum_precision_decimal_edit_helper(t_data *data, char *string)
{
	if ((data->prec > data->padnum) && data->space && data->dot
		&& !ft_char_comp('-', string) && data->padnum)
	{
		data->varl--;
		data->padnum--;
	}
	else if ((data->prec > data->padnum) && data->space && data->dot
		&& !ft_char_comp('-', string) && (data->padnum == 0))
		data->prec++;
	else if ((data->prec <= data->padnum) && data->space && data->dot
		&& !ft_char_comp('-', string))
	{
		data->prec++;
		data->padnum--;
	}
	else if (data->dot && data->space && (data->padnum > data->prec)
		&& (data->prec >= data->varl))
		data->padnum--;
}

void	padnum_precision_decimal_edit(t_data *data, char *string)
{
	if (!data->dot && (data->padnum - data->varl) >= 0)
	{
		data->padnum = data->padnum - data->varl;
		if (data->space && !ft_char_comp('-', string))
			data->padnum--;
	}
	else if (!data->dot && (data->padnum - data->varl) < 0)
		data->padnum = 0;
	else if ((data->prec > data->padnum && (data->padnum - data->varl) >= 0)
		&& data->dot)
		data->padnum = 0;
	else if ((data->padnum > data->varl && data->varl > data->prec)
		&& data->dot)
		data->padnum = data->padnum - data->varl;
	else if ((data->padnum > data->varl && data->varl <= data->prec)
		&& data->dot)
		data->padnum = data->padnum - data->prec;
	else if ((data->padnum > data->prec && data->prec < data->varl && data->dot)
		|| ((data->prec >= data->padnum && (data->padnum - data->varl) < 0)
			&& data->dot))
		data->padnum = 0;
	else if (((data->prec < data->padnum) && data->padnum < data->varl)
		&& data->dot)
		data->padnum = data->padnum - data->prec;
	padnum_precision_decimal_edit_helper(data, string);
}

static void	plus_pad_resolve_helper(t_data *data, char *string)
{
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

void	plus_pad_resolve(t_data *data, char *string)
{
	if (data->dash)
		plus_space(data, string);
	if ((((ft_char_comp('-', string) && !data->dash) && !data->dot)
			&& data->padnum < data->varl) && data->decneg)
	{
		write(1, "-", 1);
		data->counter++;
	}
	if ((((ft_char_comp('-', string) && !data->dash) && data->dot)
			&& data->padnum > 0) && (data->prec > data->padnum
			|| data->prec > data->varl))
		data->padnum--;
	if (data->padnum && !data->dash)
		ft_print_pad_dec(data, string);
	plus_pad_resolve_helper(data, string);
}
