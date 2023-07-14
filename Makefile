# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 18:45:47 by rjobert           #+#    #+#              #
#    Updated: 2023/07/12 18:01:41 by rjobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC
CFLAGS = -Wall -Werror -Wextra -MMD -I/.
HEADER = push_swap.h
SRC = sort_algorithm.c binary_tree.c data_structure.c final_rearrange.c ft_atoi_custom.c \
	ft_split.c libft_utils.c node_mapping.c parse_input.c push_stack.c \
	reverse_rotations.c rolling_algorithm.c rotations.c stack_utils.c swaps.c main.c

OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)
NAME = push_swap

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(^) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all 

.PHONY: clean fclean all re 
