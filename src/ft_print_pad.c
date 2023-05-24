/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:39:11 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/24 19:16:03 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	padnum_precision_edit(t_data *data)
{
	if (((data->padnum > data->varl) && (data->prec > data->varl)) && data->dot)
		data->padnum = data->padnum - data->varl;
	else if ((((data->padnum > data->varl) || ((data->padnum > data->prec
			|| (data->prec > data->varl)))) && (data->prec != 0))
			&& data->dot && (data->padnum > data->prec))
		data->padnum = data->padnum - data->prec;
	else if ((data->padnum > data->varl) && !data->dot)
		data->padnum = data->padnum - data->varl;
	else if (data->pre && !((data->varl > data->prec) || (data->padnum < data->pre)))
		data->padnum = data->padnum - data->pre;
	else if (((data->padnum > data->pre && data->varl > data->pre) && data->dot) && data->pre)
		data->padnum = data->padnum - data->pre;
	else
		data->padnum = 0;
}

void	ft_print_pad(t_data *data)
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
