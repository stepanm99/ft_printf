/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_resolve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:40:38 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/03 18:09:22 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_type_resolve(const char *fmt, int *counter, va_list args)
{
	fmt++;
	if (*fmt == 'c')
		ft_print_character();
	if (*fmt == 's')
		ft_print_string();
	if (*fmt == 'p')
		ft_print_pointer();
	if (*fmt == 'd')
		ft_print_decimal();
	if (*fmt == 'i')
		ft_print_integer();
	if (*fmt == 'u')
		ft_print_unsigned_int();
	if (*fmt == 'x')
		ft_print_hex_low();
	if (*fmt == 'X')
		ft_print_hex_up();
	if (*fmt == '%')
		ft_print_percent(counter);
	return (0);
}
