#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include<stdlib.h>
# include<unistd.h>
# include "Libft/libft.h"
# include<stdio.h>

int	ft_printf(const char *fmt, ...);
int	ft_type_resolve(const char *fmt, int *counter, va_list args);
int	ft_check_flag();
int	ft_print_character();
int	ft_print_decimal();
int	ft_print_flag();
int	ft_print_hex_low();
int	ft_print_hex_up();
int	ft_print_integer();
int	ft_print_percent(int *counter);
int	ft_print_pointer();
int	ft_print_string();
int	ft_print_unsigned_int();
int	main(void);

struct s_flags
{
	int	dash;
	int	zero;
	int	space;
	int	hash;
	int plus;
};

struct s_flags	ft_flaginit(void);

#endif