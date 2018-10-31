NAME = libftprintf.a
SRCS =	ft_printf.c ft_itoa_intmax.c ft_itoa_base_unsigned.c ft_itoa_unsigned.c
OFILES = ft_printf.o ft_itoa_intmax.o ft_itoa_base_unsigned.o ft_itoa_unsigned.o

INCLUDES = -I header.h
LIBFT_H = libft/libft.h
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OFILES) ./libft/*.o
	ranlib $(NAME)

clean:
	make -C libft clean
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
