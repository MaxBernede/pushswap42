# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 01:44:09 by kyuuh             #+#    #+#              #
#    Updated: 2022/12/13 15:23:49 by kyuuh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRCS =  pushswap.c\
		pivottemp.c\
		quicksort.c\
		rotas.c\
		swappush.c\
		utils.c\
		revrota.c\

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :	clean all

.PHONY: re fclean all
