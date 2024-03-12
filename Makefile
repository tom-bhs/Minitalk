NAME = minitalk

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = src/add.c src/client.c
SERVER_SRCS = src/add.c src/server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

LIBFTPRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(LIBFTPRINTF):
	make -C ft_printf/

%.o: %.c
	$(CC) $(CFLAGS) -I ft_printf -c $< -o $@

$(NAME): client server

client: $(LIBFTPRINTF) $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) $(LIBFTPRINTF) -o client

server: $(LIBFTPRINTF) $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) $(LIBFTPRINTF) -o server

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	make clean -C ft_printf/

fclean: clean
	$(RM) client server

re: fclean all

.PHONY: all clean fclean re