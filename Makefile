# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 16:23:27 by azaliaus          #+#    #+#              #
#    Updated: 2018/04/30 18:10:46 by azaliaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS_DIR = srcs/
SRCS = *.c
SRC_LST = $(addprefix $(SRCS_DIR),$(SRCS))

INCLUDES = -I libft/includes -I./includes
LIB = -L libft/ -lft

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	#cd libft && make re
	@gcc $(FLAGS) -o $(NAME) $(SRC_LST) libft/libft.a $(INCLUDES) $(LIB)
	@echo "Successfully made!"

clean:
	@echo "Everything is clean!"
	#cd libft && make clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
