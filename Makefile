# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 14:15:08 by volyvar-          #+#    #+#              #
#    Updated: 2019/07/31 16:51:01 by volyvar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME1 = checker
MAKE = make

SRCDIR = ./sources/push_swap/
SRCDIR1 = ./sources/checker/
SRCDIR0 = ./sources/

HEAD = ./header/header.h

SRC = push_swap.c find_alg.c \
	all_len.c find_median.c \
	find_sense.c not_stupid_sort.c \
	put_elements.c stupid_sort.c big_sort.c \
	middle_sort.c 
SRC1 = checker.c \
	 valid_command.c
SRC0 = extra_func.c ft_new_atoi.c list_doings.c list_doings_2.c \
		is_sorted.c valid_arg.c divide.c valid_arg_help.c flags.c \
		print_list.c find_command.c

SCRFILES = $(addprefix $(SRCDIR), $(SRC))
SCRFILES1 = $(addprefix $(SRCDIR1), $(SRC1))
SCRFILES0 = $(addprefix $(SRCDIR0), $(SRC0))

OBJS = $(SCRFILES:.c=.o)
OBJS1 = $(SCRFILES1:.c=.o)
OBJS0 = $(SCRFILES0:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L ./libft/ -lft
LIBFT = ./libft/libft.a

all:  $(NAME) $(NAME1)

%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(OBJS0) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS0) $(LDFLAGS) -o $(NAME)

$(NAME1): $(OBJS1) $(OBJS0) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS1) $(OBJS0) $(LDFLAGS) -o $(NAME1)

$(LIBFT):
	@$(MAKE) -C ./libft/

clean:
	@$(MAKE) -C ./libft/ $@
	@/bin/rm -f $(OBJS) $(OBJS0) $(OBJS1)

fclean: clean
	@$(MAKE) -C ./libft/ $@
	@/bin/rm -f $(NAME) $(NAME1)

re: fclean all

.PHONY: all, clean, fclean, re