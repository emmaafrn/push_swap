SRCS	=	actions/push.c actions/reverse_rotate.c actions/reverse_rotate.c actions/swap.c \
			algo/algo.c algo/three_or_less.c algo/above_five.c \
			libft.c list.c push_swap.c utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CFLAGS	= -Werror -Wall -Wextra

GCC  = gcc

RM  = rm -f

$(NAME): $(OBJS)
	$(GCC) ${CFLAGS} -o $(NAME)

$(OBJS) = push_swap.h

all:	$(NAME)

%.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re