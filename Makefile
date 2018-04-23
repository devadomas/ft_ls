# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 16:23:27 by azaliaus          #+#    #+#              #
#    Updated: 2018/04/23 14:53:54 by azaliaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

all: $(NAME)

$(NAME):
	#cd libft && make re
	@gcc -Wall -Wextra -Werror -o ft_ls *.c  -I libft/includes -L libft/ -lft
	@echo "Successfully made!"

clean:
	@cd libft && make clean

fclean: clean
	@rm ft_ls

re: fclean all
