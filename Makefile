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


SRC = sort_algorithm.c binary_tree.c data_structure.c final_rearrange.c ft_atoi_custom.c \
	ft_split.c libft_utils.c node_mapping.c parse_input.c push_stack.c \
	reverse_rotations.c rolling_algorithm.c rotations.c stack_utils.c swaps.c
SRC_MAIN = main.c
SRC_BONUS = gnl_checker.c gnl_checker_utils.c checker.c

OBJS = $(SRC:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
DEPS = $(SRC:.c=.d)
DEPS_MAIN = $(SRC_MAIN:.c=.d)
DEPS_BONUS = $(SRC_BONUS:.c=.d)

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

bonus: .bonus

-include $(DEPS) $(DEPS_MAIN)
$(NAME): $(OBJS) $(OBJ_MAIN)
	$(CC) $(CFLAGS) $(^) -o $(NAME)

%.o : %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS) $(DEPS_BONUS)
.bonus: $(OBJS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(^) -o $(NAME_BONUS)
	touch .bonus

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(OBJ_MAIN) $(DEPS) $(DEPS_BONUS) $(DEPS_MAIN)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS) .bonus

re: fclean all 

.PHONY: clean fclean all re 
