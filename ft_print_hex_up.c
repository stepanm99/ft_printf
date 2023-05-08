/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:15 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/05 19:45:36 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_up(t_data *data)
{
	char	*string;

	data->hexup = 1;
	string = ft_hextoa(va_arg(*data->args, size_t), data);
	if (data->hash == 1)
	{
		write(1, "0X", 2);
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
