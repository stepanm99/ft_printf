/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:15 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/19 17:44:15 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static void	print(t_data *data, char *string)
{
	while (*string != '\0')
	{
		write(1, string, 1);
		data->counter++;
		string++;
	}
}

int	ft_print_hex_up(t_data *data)
{
	char	*string;
	char	*ptr;

	data->hexup = 1;
	string = ft_hextoa(va_arg(*data->args, unsigned int), data);
	ptr = string;
	print(data, string);
	free(ptr);
	return (0);
}
