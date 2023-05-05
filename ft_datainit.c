/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datainit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:07:54 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/05 19:45:19 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	ft_datainit(va_list *args, const char *fmt)
{
	struct s_data	data;

	data.dash = 0;
	data.zero = 0;
	data.space = 0;
	data.hash = 0;
	data.plus = 0;
	data.counter = 0;
	data.args = args;
	data.fmt = fmt;
	return (data);
}
