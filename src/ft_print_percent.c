/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:24 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/09 22:24:02 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(t_data *data)
{
	char	c;

	data->varl = 1;
	if (data->padnum && !data->dash)
		ft_print_pad(data);
	c = 37;
	write(1, &c, 1);
	data->counter++;
	if (data->padnum && data->dash)
		ft_print_pad(data);
	return (0);
}
