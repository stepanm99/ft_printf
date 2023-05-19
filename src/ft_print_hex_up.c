/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:15 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/19 23:18:21 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prec(t_data *data)
{
	if (data->varl > data->prec)
		return ;
	else
		data->prec = data->prec - data->varl;
	while (data->prec !=0)
	{
		write(1, "0", 1);
		data->counter++;
		data->prec--;
	}
}

static void	print(t_data *data, char *string)
{
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
}

int	ft_print_hex_up(t_data *data)
{
	char	*string;
	char	*ptr;

	data->hexup = 1;
	string = ft_hextoa(va_arg(*data->args, unsigned int), data);
	ptr = string;
	if (*string == '0')
		data->hash = 0;
	data->varl = ft_strlen(string);
	prec(data);
	print(data, string);
	free(ptr);
	return (0);
}
