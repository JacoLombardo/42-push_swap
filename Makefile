# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 12:40:11 by jalombar          #+#    #+#              #
#    Updated: 2024/05/21 12:11:52 by jalombar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc   
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h
NAME = push_swap
LIBFTNAME = libft.a
LIBFTDIR = ./libft

all: $(NAME)

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclea

re: fclean all
