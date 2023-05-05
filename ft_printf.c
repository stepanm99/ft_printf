/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:59 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/05 21:44:42 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	checkrun(t_data *data)
{
	while (*data->fmtcount != '\0')
	{
		if (*data->fmtcount != '%')
			data->counter++;
		if (*data->fmtcount == '%')
			ft_type_resolve(data);
		data->fmtcount++;
	}
	data->write = 1;
	data->counter = 0;
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_data	data;
	t_data	*dataptr;

	va_start (args, fmt);
	data = ft_datainit(&args, fmt);
	dataptr = &data;
	checkrun(dataptr);
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
/*
	//for testing purpose
	printf("value of left %d\n", data.dash);
	printf("value of zero %d\n", data.zero);
	printf("value of space %d\n", data.space);
	printf("value of hash %d\n", data.hash);
	printf("value of plus %d\n", data.plus);
	//for testing purpose
//*/
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