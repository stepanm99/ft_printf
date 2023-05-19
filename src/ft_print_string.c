/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:30 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/19 22:51:03 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*null_case(void)
{
	char	*string;

	string = (char *)malloc(7 * (sizeof (char)));
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
	string -= 6;
	return (string);
}

static void	string_printer(char *string, t_data *data)
{
	while (*string != '\0' && data->prec > 0)
	{
		write(1, string, 1);
		data->counter++;
		string++;
		if (data->dot)
			data->prec--;
	}
}

int	ft_print_string(t_data *data)
{
	char	*string;
	char	*ptr;
	int		nullcase;

	nullcase = 0;
	string = va_arg(*data->args, char *);
	if (string == NULL)
	{
		string = null_case();
		nullcase = 1;
	}
	ptr = string;
	data->varl = ft_strlen(string);
	if (data->padnum && !data->dash)
		ft_print_pad(data);
	if (!data->dot)
		data->prec = 1;
	string_printer(string, data);
	if (data->padnum && data->dash)
		ft_print_pad(data);
	if (nullcase)
		free(ptr);
	return (0);
}
