# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 22:32:18 by mimatsub          #+#    #+#              #
#    Updated: 2022/08/05 16:07:06 by mimatsub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NORM = norminette

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	$(NORM) $(SRCS)

.PHONY: all clean fclean re norm

