SRCS	=	ft_printf.c \
				ft_printf_address.c \
				ft_printf_char.c \
				ft_printf_char.c \
				ft_printf_decimal.c \
				ft_printf_hexa.c 


OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= cc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

LIBR	= ranlib

AR		= ar rc

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${LIBR} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re