NAME = minitalk

FT_PRINTF_PATH = ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a
INCLUDES = -I ./includes -I $(FT_PRINTF_PATH)
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

SERVER_SRCS = srcs/server.c
CLIENT_SRCS = srcs/client.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER = server
CLIENT = client

RM = rm -f

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(FT_PRINTF)
	$(CC) $(SERVER_OBJS) -o $@ -L$(FT_PRINTF_PATH) -lftprintf

$(CLIENT): $(CLIENT_OBJS) $(FT_PRINTF)
	$(CC) $(CLIENT_OBJS) -o $@ -L$(FT_PRINTF_PATH) -lftprintf

$(SERVER_OBJS): $(SERVER_SRCS)
	$(CC) -c $(SERVER_SRCS) -o $@

$(CLIENT_OBJS): $(CLIENT_SRCS)
	$(CC) -c $(CLIENT_SRCS) -o $@

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(MAKE) clean -C $(FT_PRINTF_PATH)

fclean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(RM) $(SERVER) $(CLIENT)
	$(MAKE) fclean -C $(FT_PRINTF_PATH)

re: fclean all

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)

.PHONY: all clean fclean re