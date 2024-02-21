NAME		= minitalk
CFLAGS		= -Wextra -Wall -Werror

SRC			=	client.c \
				serveur.c \

all: $(NAME)

%.o: %.c


clean:
		$(RM)

fclean: clean
		$(RM)

re: fclean all
