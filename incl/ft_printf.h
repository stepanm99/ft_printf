/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:49:36 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/20 18:57:43 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../Libft/libft.h"

typedef struct s_data
{
	int			hexup;
	int			decneg;
	int			counter;
	va_list		*args;
	const char	*fmt;
}	t_data;

t_data	*ft_datainit(va_list *args, const char *fmt);

int		ft_printf(const char *fmt, ...);
int		ft_type_resolve(t_data *data);
int		ft_print_character(t_data *data);
int		ft_print_decimal(t_data *data);
int		ft_print_hex_low(t_data *data);
int		ft_print_hex_up(t_data *data);
int		ft_print_percent(t_data *data);
int		ft_print_pointer(t_data *data);
int		ft_print_string(t_data *data);
int		ft_print_unsigned_int(t_data *data);
char	*ft_utoa(unsigned int n);
char	*ft_hextoa(unsigned int n, t_data *data);

#endif