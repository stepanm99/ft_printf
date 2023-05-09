/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:20 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/09 22:25:10 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_integer(t_data *data)
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
