# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 12:40:11 by jalombar          #+#    #+#              #
#    Updated: 2024/07/12 12:13:12 by jalombar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc   
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c functions/s_p.c functions/r.c functions/rr.c source/ft_free_stack.c source/ft_handle_stack.c source/ft_lst.c source/ft_sort_three.c source/ft_sort.c source/ft_min_max.c
HEADER = push_swap.h
NAME = push_swap
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -L$(LIBFT_PATH) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
