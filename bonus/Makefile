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
SRCS = checker.c checker_utils.c ../source/create_stack.c ../source/lst.c ../source/functions/r.c ../source/functions/rr.c ../source/functions/s_p.c
HEADER = checker.h
NAME = checker
GNL_PATH = get_next_line
GNL = $(LIBFT_PATH)/get_next_line.a

all: $(NAME)

$(NAME): $(SRCS) $(GNL)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -L$(GNL_PATH) -lft

$(GNL):
	$(MAKE) -C $(GNL_PATH)

clean:
	$(MAKE) -C $(GNL_PATH) clean

fclean: clean
	$(MAKE) -C $(GNL_PATH_PATH) fclean
	rm -f $(NAME)

re: fclean all
