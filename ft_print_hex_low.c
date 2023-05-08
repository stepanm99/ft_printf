/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:11 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/05 19:45:33 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_low(t_data *data)
{
	char	*string;

	string = ft_hextoa(va_arg(*data->args, size_t), data);
	if (data->hash == 1)
	{
		write(1, "0x", 2);
		data->counter += 2;
	}
	while (*string != '\0')
		{
			write(1, string, 1);
			data->counter++;
			string++;
		}
	return (0);
}
