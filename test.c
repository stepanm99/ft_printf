#include <unistd.h>
#include <stdio.h>

void	ft_print(int argc, char *argv[])
{
	argc--;
	while (argc != 0)
	{
		printf("\nfrom the first while\n");
		while (argv[argc])
		{
			write(1, argv[argc], 1);
			if (*argv[argc] != '\0')
				argv[argc]++;
			else
				break;
		}
		argc--;
	}
	return ;
}

int	main()
{
	ft_print("test", of, this, thing);
	return(0);
}
