/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:39:11 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/15 22:29:39 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pad(t_data *data)
{
	char	c;

//	printf("padnum from printpad: %i\n", data->padnum);
	if (data->zero && !data->dash)
		c = '0';
	else
		c = ' ';
//	printf("\nafter first if\n");
//	printf("\npadnum = %i\n", data->padnum);
	if (data->padnum > data->varl)
		data->padnum = data->padnum - data->varl;
	else
		return ;
//	printf("\nafter second if\n");
	while (data->padnum != 0)
	{
//		printf("\nfrom while, padnum = %i\n", data->padnum);
		write(1, &c, 1);
		data->counter++;
		data->padnum--;
	}
}
