/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:59 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/16 23:13:48 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_data_refresh(t_data *data)
{
	data->dash = 0;
	data->zero = 0;
	data->space = 0;
	data->hash = 0;
	data->plus = 0;
	data->dot = 0;
	data->hexup = 0;
	data->padnum = 0;
	data->prec = 0;
	data->varl = 0;
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_data	data;

	va_start (args, fmt);
	data = ft_datainit(&args, fmt);
	while ((*data.fmt != '\0') && (data.write == 1))
	{
		if (*data.fmt != '%')
		{
			write (1, data.fmt, 1);
			data.counter++;
		}
		if (*data.fmt == '%')
		{
			ft_data_refresh(&data);
			ft_type_resolve(&data);
		}
		data.fmt++;
	}
	va_end (args);
	return (data.counter);
}
