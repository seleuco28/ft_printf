# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvarovelazquez <alvarovelazquez@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 17:19:36 by alvarovelaz       #+#    #+#              #
#    Updated: 2022/05/09 17:28:29 by alvarovelaz      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = ar -rcs

SRC = ft_printf_cs.c ft_printf_di.c ft_printf_p.c ft_printf_u.c ft_printf_xX.c ft_printf.c \

OBJ = $(SRC:.c=.o)

RM = rm -f

CC = gcc -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	$(LIB) $(NAME) $(OBJ)

all: $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

