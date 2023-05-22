/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:39:11 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/22 20:58:49 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pad(t_data *data)
{
	char	c;

	if (data->zero && !data->dash)
		c = '0';
	else
		c = ' ';
	if ((data->padnum > data->varl) && (data->prec == 0))
		data->padnum = data->padnum - data->varl;
	else if (((data->padnum > data->varl) && (data->prec != 0))
			&& data->dot)
		data->padnum = data->padnum - data->prec ;
	else
		return ;
	while (data->padnum != 0)
	{
		write(1, &c, 1);
		data->counter++;
		data->padnum--;
	}
}
