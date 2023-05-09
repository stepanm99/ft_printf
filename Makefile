# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 18:40:25 by smelicha          #+#    #+#              #
#    Updated: 2023/05/09 21:49:29 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC = ft_printf.c ft_datainit.c ft_check_flag.c ft_print_character.c \
	ft_print_decimal.c ft_print_flag.c ft_print_hex_low.c ft_print_hex_up.c \
	ft_print_integer.c ft_print_percent.c ft_print_pointer.c ft_print_string.c \
	ft_print_unsigned_int.c ft_type_resolve.c ft_char_comp.c ft_utoa.c \
	ft_hextoa.c ft_print_pad.c

CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@"
	@ar rcs $(NAME) $(OBJ)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@echo "Compiling and linking Libft"
	@cd Libft && make fclean && make

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: all
	@./$(NAME)

maintest: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) Libft/libft.a main.c $(FLAGS)
	@./a.out

maindebug: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) Libft/libft.a main.c -g $(FLAGS) -o prog
#for testing purposes at home on linux $(NAME) was changed to $(SRC)
	@./prog

.PHONY: all clean fclean re test