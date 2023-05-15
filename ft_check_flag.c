/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:15:25 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/15 21:24:16 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_pad_num(t_data *data)
{
	if (!data->dot)
	{
		while (ft_char_comp(*data->fmt, "0123456789"))
		{
//			printf("\nfmt ffrom getpadnum: %c\n", *data->fmt);
			data->padnum = data->padnum * 10 + (*data->fmt - '0');
			data->fmt++;
		}
	}
//	printf("padnum from getpadnum: %i\n", data->padnum);
	if (*data->fmt == '.')
		data->dot = 1;
	data->fmt++;
	if (data->dot)
	{
		while (ft_char_comp(*data->fmt, "0123456789"))
		{
			data->prec = data->prec * 10 + (*data->fmt - '0');
			data->fmt++;
		}
	}
	data->fmt -= 2;
}

void	ft_check_flag(t_data *data)
{
	while (!ft_char_comp(*data->fmt, "cspdiuxX%"))
	{
		if (*data->fmt == '-')
			data->dash = 1;
		if (*data->fmt == '0')
			data->zero = 1;
		if (*data->fmt == ' ')
			data->space = 1;
		if (*data->fmt == '#')
			data->hash = 1;
		if (*data->fmt == '+')
			data->plus = 1;
		if (ft_char_comp(*data->fmt, "0123456789") && !((data->padnum > 0)
				|| (data->prec > 0)))
			ft_get_pad_num(data);
		data->fmt++;
	}
	data->fmt--;
//	printf("padnum from checkflag: %i\n", data->padnum);
	ft_type_resolve(data);
}
