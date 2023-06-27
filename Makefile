# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 18:45:47 by rjobert           #+#    #+#              #
#    Updated: 2023/06/27 18:45:51 by rjobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = CC
CFLAGS = -Wall -Werror -Wextra
HEADER = push_swap.h
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
LIB_PATH = ./libft_printf
LIBFT = $(LIB_PATH)/libftprintf.a
NAME = push_swap

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(LIBFT):
	make -C $(LIB_PATH) all

clean:
	rm -f $(OBJS)
	make -C $(LIB_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: clean fclean all re