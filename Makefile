NAME = libftprintf.a

SRCS = 	ft_printf.c \
		helpers/ft_putchar.c \
		helpers/ft_putchar_fd.c \
		
OBJECTS = ft_printf.o \
		helpers/ft_putchar.o \
		helpers/ft_putchar_fd.o \

INCLUDES = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all