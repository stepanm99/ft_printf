/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:30 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/16 23:47:17 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*null_case(char *string)
{
	char	*ptr;

	free(string);
	string = (char *)malloc(7 * (sizeof (char)));
	ptr = string;
	*string = '(';
	string++;
	*string = 'n';
	string++;
	*string = 'u';
	string++;
	*string = 'l';
	string++;
	*string = 'l';
	string++;
	*string = ')';
	string++;
	*string = '\0';
	string++;
	return (ptr);
}

int	ft_print_string(t_data *data)
{
	char	*string;
	char	*ptr;

	string = va_arg(*data->args, char *);
	ptr = string;
	if (string == NULL)
		string = null_case(string);
	data->varl = ft_strlen(string);
	if (data->padnum && !data->dash)
		ft_print_pad(data);
	if (!data->dot)
		data->prec = 1;
	while (*string != '\0' && data->prec > 0)
	{
		write(1, string, 1);
		data->counter++;
		string++;
		if (data->dot)
			data->prec--;
	}
	if (data->padnum && data->dash)
		ft_print_pad(data);
	free(ptr);
	return (0);
}
