/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:36:43 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/21 22:16:19 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

static double	check_neg(t_data *data, double n)
{
	if (n < 0.0)
	{
		n = n * (-1);
		data->decneg = 1;
		write(1, "-", 1);
		data->counter++;
	}
	return (n);
}

int	ft_print_float(t_data *data)
{
	char	*string;
	char	*ptr;
	double	n;

	n = check_neg(data, va_arg(*data->args, double));
	string = ft_ftoa(n, 10);
	ptr = string;
	if ((*string == '-') || (*string == '-' && data->decneg))
		string++;
	while (*(string + 1) != '\0')
	{
		write(1, string, 1);
		data->counter++;
		string++;
	}
	free(ptr);
	return (0);
}