/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:15 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/10 23:46:43 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_up(t_data *data)
{
	char	*string;
	char	*ptr;

	data->hexup = 1;
	string = ft_hextoa(va_arg(*data->args, size_t), data);
	ptr = string;
	data->varl = ft_strlen(string);
	if (data->padnum && !data->dash)
		ft_print_pad(data);
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
	if (data->padnum && data->dash)
		ft_print_pad(data);
	free(ptr);
	return (0);
}
