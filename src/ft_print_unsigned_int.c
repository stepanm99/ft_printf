/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:33 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/19 17:44:28 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

int	ft_print_unsigned_int(t_data *data)
{
	char			*string;
	char			*ptr;
	unsigned int	n;

	n = (unsigned int)va_arg(*data->args, unsigned int);
	string = ft_utoa(n);
	ptr = string;
	while (*string != '\0')
	{
		write(1, string, 1);
		data->counter++;
		string++;
	}
	free(ptr);
	return (0);
}
