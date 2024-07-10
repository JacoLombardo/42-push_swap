# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 12:40:11 by jalombar          #+#    #+#              #
#    Updated: 2024/07/10 14:35:54 by jalombar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc   
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h
NAME = push_swap
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)


$(NAM): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_PATH) -lft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
