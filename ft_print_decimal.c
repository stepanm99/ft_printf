/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:09:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/10 23:33:08 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//decimal could be with floating point???

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

int	ft_print_decimal(t_data *data)
{
	char	*string;
	char	*ptr;

	string = ft_itoa(va_arg(*data->args, int));
	ptr = string;
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
	free(ptr);
	return (0);
}
