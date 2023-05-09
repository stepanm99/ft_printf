/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:20 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/10 00:47:33 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	plus_space(t_data *data, char *string)
{
	if ((data->padnum > 0) && !ft_char_comp('-', string))
			data->padnum--;
	if (!ft_char_comp('-', string) && data->plus && !(data->padnum > 0))
	{
		write(1, "+", 1);
		data->counter++;
	}
	if (!ft_char_comp('-', string) && data->space && !(data->padnum > 0) &&
			!data->plus)
	{
		write(1, " ", 1);
		data->counter++;
	}
}

int	ft_print_integer(t_data *data)
{
	char	*string;

	string = ft_itoa(va_arg(*data->args, int));
	data->varl = ft_strlen(string);
	plus_space(data, string);
	if (data->padnum && !data->dash)
		ft_print_pad(data);
	plus_space(data, string);
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
