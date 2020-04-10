# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 17:51:43 by volyvar-          #+#    #+#              #
#    Updated: 2019/07/31 17:03:14 by volyvar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGC = -Wall -Wextra -Werror

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c  \
ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
ft_strnstr.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c  \
ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c  \
ft_lstmap.c ft_strcmp.c ft_strncmp.c ft_strncat.c ft_find_c.c ft_isgraph.c ft_isblank.c ft_min.c \
ft_max.c get_next_line.c

SRCPATH1 = ./ft_printf/sources/

SRC1 = c_conservation.c di_cons.c do_consver.c \
	  ft_itoa_base.c ft_printf.c ft_read_arg.c \
	  o_conservation.c s_conservation.c p_conservation.c \
	  x_conservation.c x_up_conservation.c di_func.c \
	  ft_size.c ft_size_u.c u_cons.c ft_size_1.c \
	  ft_size_2.c ft_size_3.c ft_size_u_1.c ft_size_u_2.c \
	  ft_size_u_3.c di_func_1.c di_func_3.c di_cons_2.c float.c \
	  bnt.c multik.c f_cons.c f_wid.c f_cons_str.c di_ost.c \
	  f_ost.c f_cons_str_h.c float_h.c ft_float_hh.c \
	  float_hhh.c multik_h.c sl_conservation.c cl_cons.c \
	  nan.c last_func.c ft_last_func_2.c do_len.c do_flags.c \
	  do_wid.c do_type.c

SCRFILES1 = $(addprefix $(SRCPATH1), $(SRC1))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ1 = $(SCRFILES1:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(OBJ1)
	@ar rc $(NAME) $(OBJ)
	@ar rc $(NAME) $(OBJ1)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(OBJ1)

fclean: clean
	@rm -f $(NAME)

re: fclean all
