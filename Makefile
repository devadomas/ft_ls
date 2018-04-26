# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaliaus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 16:23:27 by azaliaus          #+#    #+#              #
#    Updated: 2018/04/26 17:06:29 by azaliaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

all: $(NAME)

sandbox: re $(NAME)
	@cp ft_ls sandbox
	@echo "ft_ls copied to sandbox"

$(NAME):
	#cd libft && make re
	@gcc -Wall -Wextra -Werror -o ft_ls *.c  -I libft/includes -L libft/ -lft
	@echo "Successfully made!"

clean:
	@echo "Everything is clean!"
	#cd libft && make clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
