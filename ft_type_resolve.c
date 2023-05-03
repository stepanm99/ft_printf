/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_resolve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:40:38 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/03 20:03:08 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_type_resolve(t_data data)
{
	data.fmt++;
	if (*data.fmt == 'c')
		ft_print_character();
	if (*data.fmt == 's')
		ft_print_string();
	if (*data.fmt == 'p')
		ft_print_pointer();
	if (*data.fmt == 'd')
		ft_print_decimal();
	if (*data.fmt == 'i')
		ft_print_integer();
	if (*data.fmt == 'u')
		ft_print_unsigned_int();
	if (*data.fmt == 'x')
		ft_print_hex_low();
	if (*data.fmt == 'X')
		ft_print_hex_up();
	if (*data.fmt == '%')
		ft_print_percent(data);
	return (0);
}
