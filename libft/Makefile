# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaliaus <azaliaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 15:12:15 by azaliaus          #+#    #+#              #
#    Updated: 2018/05/01 08:25:30 by azaliaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -g
NAME = libft.a
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	   ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	   ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	   ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	   ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	   ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	   ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putchar.c \
	   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_strsplit.c ft_get_next_word.c \
	   ft_itoa.c ft_get_nbr_len.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_str_upper.c ft_str_lower.c \
	   ft_strrev.c ft_convert_to_base.c ft_convert_to_base_long.c \
	   ft_putnbr_unsigned.c ft_pow.c ft_putchar_unicode.c ft_atoi_longlong.c \
	   ft_unicode_len.c ft_putnbr_longlong.c ft_putchar_ret.c \
	   ft_get_nbr_len_unsigned.c ft_strjoin_conn.c ft_floor.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Libft compiled!"

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $< -I./includes

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
