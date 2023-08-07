SERVER=server

CLIENT=client

FLAGS= -Wall -Wextra -Werror

SRC1 = server.c server_utils.c

SRC2 = client.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ1) 
	gcc $(OBJ1) -o server

$(CLIENT) : $(OBJ2)
	gcc $(OBJ2) -o client

%.o : %.c
	gcc $(FLAGS) -c $^ -o $@

clean :
	rm -f $(OBJ1) $(OBJ2)

fclean : clean
	rm -f $(SERVER) $(CLIENT)

re : fclean all
