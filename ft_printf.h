#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include<stdlib.h>
# include<unistd.h>
#include <stdarg.h>
# include "Libft/libft.h"
# include<stdio.h>

typedef struct s_data
{
	int			dash;
	int			zero;
	int			space;
	int			hash;
	int 		plus;
	int			counter;
	va_list		*args;
	const char	*fmt;
} t_data;

t_data	ft_datainit(va_list *args, const char *fmt);

int	ft_printf(const char *fmt, ...);
int	ft_type_resolve(t_data *data);
int	ft_check_flag(t_data *data);
int	ft_print_character(t_data *data);
int	ft_print_decimal(t_data *data);
int	ft_print_flag(t_data *data);
int	ft_print_hex_low(t_data *data);
int	ft_print_hex_up(t_data *data);
int	ft_print_integer(t_data *data);
int	ft_print_percent(t_data *data);
int	ft_print_pointer(t_data *data);
int	ft_print_string(t_data *data);
int	ft_print_unsigned_int(t_data *data);
int	ft_char_comp(char c, char *set);

#endif