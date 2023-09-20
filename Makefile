# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 18:40:25 by smelicha          #+#    #+#              #
#    Updated: 2023/09/20 18:58:11 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC = ft_printf.c src/ft_datainit.c src/ft_hextoa.c \
		src/ft_print_character.c src/ft_print_decimal.c \
		src/ft_print_hex_low.c src/ft_print_hex_up.c src/ft_print_percent.c \
		src/ft_print_pointer.c src/ft_print_string.c \
		src/ft_print_unsigned_int.c src/ft_type_resolve.c src/ft_utoa.c \

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

clean:
	@rm -f $(OBJ) $(OBJB)
	@make clean -C ./Libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./Libft

re: fclean all

test: all
	@./$(NAME)

maintest: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(SRC) Libft/libft.a main.c $(FLAGS)
	@./a.out

maindebug: all
	@echo "~~~ Testing with main function ~~~"
	@$(CC) $(NAME) Libft/libft.a main.c -g $(FLAGS) -o prog
	@./prog

.PHONY: all clean fclean re test bonus maintest maindebug