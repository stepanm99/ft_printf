/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:11 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/10 23:46:18 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_low(t_data *data)
{
	char	*string;
	char	*ptr;

	string = ft_hextoa(va_arg(*data->args, size_t), data);
	ptr = string;
	data->varl = ft_strlen(string);
	if (data->padnum && !data->dash)
		ft_print_pad(data);
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
	if (data->padnum && data->dash)
		ft_print_pad(data);
	free(ptr);
	return (0);
}
