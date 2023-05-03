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
int	ft_type_resolve(t_data data);
int	ft_check_flag();
int	ft_print_character();
int	ft_print_decimal();
int	ft_print_flag();
int	ft_print_hex_low();
int	ft_print_hex_up();
int	ft_print_integer();
int	ft_print_percent(t_data data);
int	ft_print_pointer();
int	ft_print_string();
int	ft_print_unsigned_int();
int	main(void);

#endif