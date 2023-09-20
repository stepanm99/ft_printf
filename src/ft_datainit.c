/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datainit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:07:54 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/19 18:18:34 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

t_data	*ft_datainit(va_list *args, const char *fmt)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->hexup = 0;
	data->decneg = 0;
	data->counter = 0;
	data->args = args;
	data->fmt = fmt;
	return (data);
}
