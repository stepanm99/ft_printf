#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include<stdlib.h>
# include<unistd.h>
# include "Libft/libft.h"

int	ft_printf(const char *fmt, ...);
int	main(void);

typedef struct s_flags
{
	int	left;
	int	zero;
	int	space;
	int	hash;
	int plus;
};

#endif