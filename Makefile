NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

SRC= ft_printf.c ft_d.c ft_hex.c \
ft_pointer.c ft_printf.c ft_string.c ft_utility.c

RM=rm -f

OBJ=$(SRC:.c=.o)

$(NAME): ft_printf.h
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)
	
all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
