/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:30 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/05 19:45:50 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(t_data *data)
{
	char	*string;

	string = va_arg(*data->args, char *);
	while (*string != '\0')
		{
			write(1, string, 1);
			data->counter++;
			string++;
		}
	return (0);
}
