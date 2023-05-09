/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:09:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/09 22:27:10 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//decimal could be with floating point!!!

int	ft_print_decimal(t_data *data)
{
	char	*string;

	string = ft_itoa(va_arg(*data->args, int));
	data->varl = ft_strlen(string);
	if (data->padnum && !data->dash)
		ft_print_pad(data);
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
