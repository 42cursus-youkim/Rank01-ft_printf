# Just to mess up with prod, fix .Makefile on final

TARGET = test.out

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

RAWSRC = main printf
SRC =	$(addprefix ./ft_,		$(addsuffix	.c,			$(SRCLST)))
OBJ =	$(SRC:%.c=%.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
# $@ == curr. target. name
# $^ == curr. dependancy. list

clean:
	$(RM) TARGET OBJ