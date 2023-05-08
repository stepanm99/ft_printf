/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:15:25 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/08 21:35:42 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(t_data *data)
{
	while (!ft_char_comp(*data->fmt, "cspdiuxX%"))
	{
		if (*data->fmt == '-')
			data->dash = 1;
		if (*data->fmt == '0')
			data->zero = 1;
		if (*data->fmt == ' ')
			data->space = 1;
		if (*data->fmt == '#')
			data->hash = 1;
		if (*data->fmt == '+')
			data->plus = 1;
		data->fmt++;
	}
	data->fmt--;
	ft_type_resolve(data);
}
