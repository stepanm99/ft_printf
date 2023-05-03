/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:59 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/03 20:08:28 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_data	data;

	va_start (args, fmt);
	data = ft_datainit(&args, fmt);
	while (*data.fmt != '\0')
	{
		if (*data.fmt != '%')
		{
			write (1, data.fmt, 1);
			data.counter++;
		}
		if (*data.fmt == '%')
		{
			ft_type_resolve(data);
		}
		data.fmt++;
	}
	va_end (args);
	return (data.counter);
}

/*
FIRST PROTOTYPE

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	char	*test;

	va_start (args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			write(1, fmt, 1);
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'q')
			{
				test = va_arg(args, char *);
				while (*test != '\0')
				{
					write(1, test, 1);
					test++;
				}
			}
			if (*fmt == 'd')
			{
				test = ft_itoa(va_arg(args, int));
				while (*test != '\0')
				{
					write(1, test, 1);
					test++;
				}
			}
		}
		fmt++;
	}
	va_end (args);
	return (0);
}
*/