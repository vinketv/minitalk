CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

LIBFT_DIR = libft
LIBFT_SRCS = $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_printf.c
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o) $(LIBFT_OBJS)
SERVER_OBJS = $(SERVER_SRCS:.c=.o) $(LIBFT_OBJS)

CLIENT_NAME = client
SERVER_NAME = server

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
