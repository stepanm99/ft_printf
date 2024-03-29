/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_resolve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:40:38 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/06 14:21:51 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	ft_type_resolve(t_data *data)
{
	data->fmt++;
	if (*data->fmt == 'c')
		ft_print_character(data);
	if (*data->fmt == 's')
		ft_print_string(data);
	if (*data->fmt == 'p')
		ft_print_pointer(data);
	if (*data->fmt == 'd')
		ft_print_decimal(data);
	if (*data->fmt == 'i')
		ft_print_decimal(data);
	if (*data->fmt == 'u')
		ft_print_unsigned_int(data);
	if (*data->fmt == 'x')
		ft_print_hex_low(data);
	if (*data->fmt == 'X')
		ft_print_hex_up(data);
	if (*data->fmt == '%')
		ft_print_percent(data);
	return (0);
}
