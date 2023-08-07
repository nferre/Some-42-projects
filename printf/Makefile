NAME = libftprintf.a

DIRLIB = ./libft/

FLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c\
	  printf_tools.c\
	  printf_tools_putnbr.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME) : $(OBJ)
	cd ${DIRLIB} && ${MAKE} && cp libft.a ../${NAME}
	ar rsc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

fclean : clean
	rm -f $(NAME)

clean : 
	rm -f $(OBJ)

re : fclean all
