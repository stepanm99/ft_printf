/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:59 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/10 23:49:09 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_data	data;
	t_data	*dataptr;

	va_start (args, fmt);
	data = ft_datainit(&args, fmt);
	dataptr = &data;
	while ((*data.fmt != '\0') && (data.write == 1))
	{
		if (*data.fmt != '%')
		{
			write (1, data.fmt, 1);
			data.counter++;
		}
		if (*data.fmt == '%')
			ft_type_resolve(dataptr);
		data.fmt++;
	}
	va_end (args);
	return (data.counter);
}
