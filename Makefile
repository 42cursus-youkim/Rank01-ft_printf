# Just to mess up with prod, fix .Makefile on final

TARGET = test.out
LIBFT = libft

CC = gcc
CFLAGS = # -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

RAWSRC = main printf
SRC =	$(addprefix ./ft_,	$(addsuffix	.c,	$(RAWSRC)))
OBJ =	$(SRC:%.c=%.o)

$(TARGET): $(OBJ)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT).a $(TARGET)
	$(CC) $(CFLAGS) -o $@ $^
# $@ == curr. target. name
# $^ == curr. dependancy. list

all: $(TARGET)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(TARGET)

re: fclean all