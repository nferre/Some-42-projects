NAME = so_long

FLAGS = -Wall -Werror -Wextra

SRC = so_long.c\
	print.c\
	parse.c\
	move.c\
	draw.c\
	check.c

OBJ= ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) 
	cc $(OBJ) -l mlx -framework OpenGL -framework AppKit -o $(NAME)


%.o: %.c
	cc $(FLAGS)  -c $^ -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all clean
