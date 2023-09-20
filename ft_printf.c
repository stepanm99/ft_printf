/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:59 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/19 20:21:09 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/ft_printf.h"

static void	ft_data_refresh(t_data *data)
{
	data->hexup = 0;
	data->decneg = 0;
}

static void	ft_data_null(t_data *data)
{
	data->hexup = 0;
	data->counter = 0;
	data->args = NULL;
	data->fmt = NULL;
	free(data);
}

static void	ft_printf_loop(t_data *data)
{
	while (*data->fmt != '\0')
	{
		if (*data->fmt != '%')
		{
			write (1, data->fmt, 1);
			data->counter++;
		}
		if (*data->fmt == '%')
		{
			ft_data_refresh(data);
			ft_type_resolve(data);
		}
		data->fmt++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_data	*data;
	int		count;

	va_start (args, fmt);
	data = ft_datainit(&args, fmt);
	if (!data)
		return (-1);
	ft_printf_loop(data);
	va_end (args);
	count = data->counter;
	ft_data_null(data);
	return (count);
}
