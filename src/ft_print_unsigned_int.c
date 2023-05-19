/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:33 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/19 23:12:02 by smelicha         ###   ########.fr       */
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

int	ft_print_unsigned_int(t_data *data)
{
	char			*string;
	char			*ptr;
	unsigned int	n;

	n = (unsigned int)va_arg(*data->args, unsigned int);
	string = ft_utoa(n);
	ptr = string;
	data->varl = ft_strlen(string);
	prec(data);
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
	free(ptr);
	return (0);
}
