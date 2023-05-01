# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 18:40:25 by smelicha          #+#    #+#              #
#    Updated: 2023/05/01 19:20:48 by smelicha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC = main.c test.c

CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJB)
	@echo "Linking $@"
	@ar rcs $(NAME) $(OBJ) $(OBJB)
	@echo "Done!"

bonus: $(OBJB)
	@echo "Linking $@"
	@ar rcs libft.a $(OBJB)
	@echo "Done!"

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: all clean fclean re test bonus