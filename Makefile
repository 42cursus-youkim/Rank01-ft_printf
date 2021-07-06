# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 16:31:20 by youkim            #+#    #+#              #
#    Updated: 2021/07/06 16:33:47 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft

CC = gcc
CFLAGS = # -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

RAWPRT = literal number #utils
RAWSRC = ft_printf utils $(PRT)

PRT = $(addprefix print_, $(RAWPRT))
SRC = $(addsuffix .c, $(RAWSRC))
OBJ = $(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT).a $(NAME)
	$(AR) $@ $^
# $@ -> curr. target. name
# $^ -> curr. dependancy. list

all: $(NAME)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS) -c -o main.o main.c
	$(CC) -o test.out -L. $(NAME) main.o
	./test.out

retest: re test

.PHONY: all clean fclean re test bonus