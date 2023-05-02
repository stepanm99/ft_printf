/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:59 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/02 23:20:28 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"
#include "Libft/libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int	count;
	int	*counter;

	count = 0;
	counter = &count;
	va_start (args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			write (1, fmt, 1);
			count++;
		}
		if (*fmt == '%')
			type_resolve(fmt, conter);
		fmt++;
	}
	va_end (args);
	return (count);
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