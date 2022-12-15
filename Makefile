# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuuh <kyuuh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 01:44:09 by kyuuh             #+#    #+#              #
#    Updated: 2022/12/15 14:12:15 by kyuuh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRCS =  srcs/pivottemp.c\
		srcs/print.c\
		srcs/pushswap.c\
		srcs/quicksort.c\
		srcs/rotas.c\
		srcs/revrota.c\
		srcs/smolsort.c\
		srcs/swappush.c\
		srcs/utils.c\

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
