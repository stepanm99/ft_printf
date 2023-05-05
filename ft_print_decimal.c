/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:09:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/05 19:45:26 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//decimal could be with floating point!!!

int	ft_print_decimal(t_data *data)
{
	char	*string;

	string = ft_itoa(va_arg(*data->args, int));
	while (*string != '\0')
		{
			write(1, string, 1);
			data->counter++;
			string++;
		}
	return (0);
}
