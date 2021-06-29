# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 14:32:23 by youkim            #+#    #+#              #
#    Updated: 2021/06/29 13:01:13 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCLST	=	memset bzero memcpy memccpy memmove memchr memcmp\
			putchar_fd putstr_fd putendl_fd putnbr_fd
SRCLSB	=	new add_front size last add_back delone clear iter map

SOURCES	=	$(addprefix ./ft_,		$(addsuffix	.c,			$(SRCLST)))
SOURCEB	=	$(addprefix ./ft_lst,	$(addsuffix	.c,			$(SRCLSB)))

OBJECTS	=	$(SOURCES:%.c=%.o)
OBJECTB	=	$(SOURCEB:%.c=%.o)

$(NAME): $(OBJECTS)
	$(AR) $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

bonus: $(OBJECTS) $(OBJECTB) $(OBJECTC)
	$(AR) $(NAME) $(OBJECTS) $(OBJECTB) $(OBJECTC)

clean:
	$(RM) $(OBJECTS) $(OBJECTB) $(OBJECTC)

fclean: clean
	$(RM) $(NAME)

re: fclean all

solo: all clean

.PHONY: make bonus all clean fclean re solo
