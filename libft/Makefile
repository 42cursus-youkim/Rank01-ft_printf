# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 14:32:23 by youkim            #+#    #+#              #
#    Updated: 2021/05/14 14:32:27 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCLST	=	memset bzero memcpy memccpy memmove memchr memcmp\
			isalpha isdigit isalnum isascii isprint toupper tolower calloc strdup\
			strlen strlcpy strlcat strchr strrchr strnstr strncmp atoi\
			substr strjoin strtrim split itoa strmapi\
			putchar_fd putstr_fd putendl_fd putnbr_fd
SRCLSB	=	new add_front size last add_back delone clear iter map
SRCLSC  =	abs sign islower isupper purge2str

SOURCES	=	$(addprefix ./ft_,		$(addsuffix	.c,			$(SRCLST)))
SOURCEC =	$(addprefix ./ft_,		$(addsuffix	_bonus.c,	$(SRCLSC)))
SOURCEB	=	$(addprefix ./ft_lst,	$(addsuffix	.c,			$(SRCLSB)))

OBJECTS	=	$(SOURCES:%.c=%.o)
OBJECTC	=	$(SOURCEC:%.c=%.o)
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
