/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:11 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/29 18:39:14 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(t_data *data, char *string)
{
	while (*string != '\0')
	{
		write(1, string, 1);
		data->counter++;
		string++;
	}
}

static void	prec(t_data *data)
{
	if (data->varl > data->prec)
		return ;
	else
		data->prec = data->prec - data->varl;
	while (data->prec != 0)
	{
		write(1, "0", 1);
		data->counter++;
		data->prec--;
	}
}

int	ft_print_hex_low(t_data *data)
{
	char	*string;
	char	*ptr;

	string = ft_hextoa(va_arg(*data->args, unsigned int), data);
	ptr = string;
	if (*string == '0')
		data->hash = 0;
	data->varl = ft_strlen(string);
	prec(data);
	if (data->padnum && !data->dash)
		ft_print_pad(data);
	if (data->hash == 1)
	{
		write(1, "0x", 2);
		data->counter += 2;
	}
	print(data, string);
	if (data->padnum && data->dash)
		ft_print_pad(data);
	free(ptr);
	return (0);
}
