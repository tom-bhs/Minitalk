NAME = minitalk

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = src/client.c
SERVER_SRCS = src/server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): client server

client: $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o client

server: $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o server

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	$(RM) client server

re: fclean all

.PHONY: all client server clean fclean re