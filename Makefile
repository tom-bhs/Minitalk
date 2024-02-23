NAME = minitalk

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = src/client.c
SERVER_SRCS = src/serveur.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): client serveur

client: $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o client

serveur: $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o serveur

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	$(RM) client serveur

re: fclean all

.PHONY: all client serveur clean fclean re