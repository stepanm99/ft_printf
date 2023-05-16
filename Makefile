# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 18:40:25 by smelicha          #+#    #+#              #
#    Updated: 2023/05/17 00:21:37 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCDIR = ./src/

SRC = $(shell find . -name "ft_printf.c" -o -name "ft_datainit.c" -o -name \
					"ft_check_flag.c" -o -name "ft_print_character.c" -o -name \
					"ft_print_decimal.c" -o -name "ft_print_flag.c" -o -name \
					"ft_print_hex_low.c" -o -name "ft_print_hex_up.c" -o -name \
					"ft_print_integer.c" -o -name "ft_print_percent.c" -o -name \
					"ft_print_pointer.c" -o -name "ft_print_string.c" -o -name \
					"ft_print_unsigned_int.c" -o -name "ft_type_resolve.c" -o -name \
					"ft_char_comp.c" -o -name "ft_utoa.c" -o -name \
					"ft_hextoa.c" -o -name "ft_print_pad.c" -type f)

CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	@make -C ./Libft
	@cp ./Libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

#libft:
#	@echo "Compiling and linking Libft"
#	@cd Libft && make fclean && make

clean:
	@rm -f $(OBJ) $(OBJB)
	@make clean -C ./Libft

fclean: clean
	@rm -f $(NAME)
#	@make fcelan -C ./Libft

re: fclean all

test: all
	@./$(NAME)

bonus: all

maintest: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) Libft/libft.a main.c leakcheck.c $(FLAGS)
	@./a.out

maindebug: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) Libft/libft.a main.c -g $(FLAGS) -o prog
#for testing purposes at home on linux $(NAME) was changed to $(SRC)
	@./prog

.PHONY: all clean fclean re test bonus maintest maindebug