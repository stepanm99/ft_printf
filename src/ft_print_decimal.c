/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:09:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/18 23:13:49 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	plus_space(t_data *data, char *string)
{
	if ((ft_char_comp('-', string)) && data->plusspace)
	{
		data->plusspace = 0;
	}
	if (!ft_char_comp('-', string) && data->plus)
	{
		write(1, "+", 1);
		data->counter++;
		data->varl++;
	}
	if (!ft_char_comp('-', string) && data->space && (data->padnum > 0))
	{
		write(1, " ", 1);
		data->counter++;
		data->varl++;
	}
}

static void	plus_pad_resolve(t_data *data, char *string)
{
	if (data->dash)
		plus_space(data, string);
	if (ft_char_comp('-', string) && !data->dash)
	{
		write(1, "-", 1);
		data->counter++;
	}
	if (data->padnum && !data->dash)
		ft_print_pad(data);
	if (!data->dash)
		plus_space(data, string);
}
/* just an idea, may not work...
static void	prec(t_data *data)
{
	if (data->varl > data->prec)
		return ;
	else
		data->prec = data->prec - data->varl;
	while (data->prec !=0)
	{
		write(1, "0", 1);
		data->counter++;
		data->prec--;
	}
}*/

int	ft_print_decimal(t_data *data)
{
	char	*string;
	char	*ptr;

	string = ft_itoa(va_arg(*data->args, int));
	ptr = string;
	data->varl = ft_strlen(string);
	plus_pad_resolve(data, string);
	if (*string == '-' && !data->dash)
		string++;
	while (*string != '\0')
	{
		write(1, string, 1);
		data->counter++;
		string++;
	}
	if (data->padnum && data->dash)
		ft_print_pad(data);
	free(ptr);
	return (0);
}
