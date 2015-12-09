#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 10:38:16 by rdestreb          #+#    #+#              #
#    Updated: 2015/11/20 12:09:14 by rdestreb         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select
SRCDIR = ./src
HEADDIR = ./
HEAD = ft_select.h
HEADFILES = $(addprefix $(HEADDIR)/, $(HEAD))
SCRFILES = $(addprefix $(SRCDIR)/, $(SRC))
SRC =	test.c \
		print_error.c \

OBJS = $(SCRFILES:.c=.o)
CC = clang
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L. -ltermcap -L ./libft/ -lft
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C ./libft/

%.o: %.c $(HEADERFILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C ./libft/ $@
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft/ $@
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
