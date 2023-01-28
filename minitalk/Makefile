CLIENT_SRCS	=	client.c

SERVER_SRCS	=	server.c

SRCS		= $(CLIENT_SRCS) $(SERVER_SRCS)

OBJS		=	$(SRCS:.c=.o)

CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)

SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)

CLIENT_NAME	=	client

SERVER_NAME	=	server

LIBFT_NAME	= libft.a

CC		= cc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(LIBFT_NAME) $(CLIENT_NAME) $(SERVER_NAME)

$(LIBFT_NAME):	
			$(MAKE) all -C ./libft

$(CLIENT_NAME):	$(CLIENT_OBJS)
			$(CC) -o $(CLIENT_NAME) $(CFLAGS) $(CLIENT_OBJS) ./libft/libft.a

$(SERVER_NAME): $(SERVER_OBJS)
			$(CC) -o $(SERVER_NAME) $(CFLAGS) $(SERVER_OBJS) ./libft/libft.a

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re:			fclean all

.PHONY:		all clean fclean re client server