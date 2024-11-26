NAME = libftprintf.a
SOURCES = \
		ft_printf.c ft_putchar.c ft_strlen.c ft_putstr.c ft_putnbr.c \
		ft_putnbr_base.c ft_putunbr.c ft_putaddress.c ft_strchr.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $?

%.o: %.c ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re