/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:09:35 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/05 19:45:23 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static void	print_character_check(t_data *data)
{
	va_arg(*data->argscount, int);
	data->counter++;
}*/

int	ft_print_character(t_data *data)
{
	char	c;

//	if (data->write == 0)
//		print_character_check(data);
//	else
//	{
	c = (char) va_arg(*data->args, int);
	write(1, &c, 1);
	data->counter++;
//	}
	return (0);
}
