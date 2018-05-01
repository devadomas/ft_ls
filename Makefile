# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 16:23:27 by azaliaus          #+#    #+#              #
#    Updated: 2018/04/30 21:40:21 by azaliaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs
SRCS = acl.c checker.c directory.c errors.c file_direct.c file_list.c \
		files_sorts.c files.c format_long.c format.c ft_ls.c helper.c main.c \
		memory.c offsets.c options.c print_helper.c print.c sort.c

INCLUDES = -I./libft/includes -I./includes

LIB_PATH = libft
LIB_LINK = -L $(LIB_PATH) -lft
LIB = $(LIB_PATH)/libft.a

SOURCES = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJECTS)
	@gcc $(FLAGS) -o $@ $^ $(LIB_LINK)
	@echo "Successfully made!"

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@make clean -C libft
	@rm -f $(OBJECTS)
	@echo "Everything is clean!"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
