/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:33 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/10 23:48:39 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_int(t_data *data)
{
	char	*string;
	char	*ptr;

	string = ft_utoa(va_arg(*data->args, size_t));
	ptr = string;
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
	free(ptr);
	return (0);
}
