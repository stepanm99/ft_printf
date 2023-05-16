/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:30 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/15 19:49:47 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(t_data *data)
{
	char	*string;

	string = va_arg(*data->args, char *);
	if (string == NULL)
	{
		write(1, "(null)", 6);
		data->counter += 6;
		return (0);
	}
	data->varl = ft_strlen(string);
	if (data->padnum && !data->dash)
		ft_print_pad(data);
	if (!data->dot)
		data->prec = 1;
	while (*string != '\0' && data->prec > 0)
	{
		write(1, string, 1);
		data->counter++;
		string++;
		if (data->dot)
			data->prec--;
	}
	if (data->padnum && data->dash)
		ft_print_pad(data);
	return (0);
}
