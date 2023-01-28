ERROR_SRCS	=	./src/error/error_handler.c

GAME_SRCS	=	./src/game/game_handler.c \
					./src/game/game_initalizer.c \
					./src/game/game_render.c \

KEY_SRCS	=	./src/key/key_handler.c

MAP_SRCS	= ./src/map/map_checker_helper.c \
				./src/map/map_checker.c \
				./src/map/map_path_checker.c \

MAIN_SRCS	= main.c

SRCS		= $(ERROR_SRCS) $(GAME_SRCS) $(KEY_SRCS) $(MAP_SRCS) $(MAIN_SRCS)

OBJS		=	$(SRCS:.c=.o)

LIBFT_A		= libft.a

MLXFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

NAME	= so_long

CC		= cc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all:		$(NAME)

${NAME}:	$(OBJS)
			$(MAKE) all -C ./libft
			$(MAKE) all -C ./minilibx-linux
			$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(MLXFLAGS) ./libft/libft.a

clean:
			$(MAKE) clean -C ./libft
			$(MAKE) clean -C ./minilibx-linux
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

test:		$(NAME)
			./so_long maps/map.ber

.PHONY: all clean fclean re so_long
