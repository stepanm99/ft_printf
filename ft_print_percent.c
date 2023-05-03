/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:10:24 by smelicha          #+#    #+#             */
/*   Updated: 2023/05/03 18:08:38 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_percent(int *counter)
{
	int		count;
	char	c;

	c = 37;
	count = *counter;
	write(1, &c, 1);
	printf("\nvalue of counter in printpercent: %d\n", count);
	count++;
	printf("\nvalue of counter in printpercent: %d\n", count);
	*counter = count;
	return (0);
}
