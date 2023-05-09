/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:27 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/09 22:13:20 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(t_data *data)
{
	char	*string;

	string = ft_hextoa(va_arg(*data->args, uintptr_t), data);
	data->varl = ft_strlen(string);
	if (data->padnum && !data->dash)
		ft_print_pad(data);
	write(1, "0x", 2);
	data->counter += 2;
	while (*string != '\0')
	{
		write(1, string, 1);
		data->counter++;
		string++;
	}
	if (data->padnum && data->dash)
		ft_print_pad(data);
	return (0);
}
