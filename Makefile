NAME	=	push_swap

SRCS	=	actions/push.c actions/reverse_rotate.c actions/rotate.c actions/swap.c \
			algo/algo.c algo/three_or_less.c algo/above_five.c algo/sort_a.c algo/three_or_less.c\
			libft.c list.c main.c utils.c checker.c

OBJ = ${SRCS:.c=.o}

CC  = gcc

RM  = rm -f

CFLAGS = -Wall -Wextra -Werror

all:		$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) ${CFLAGS} $^ -o $(NAME)

$(OBJ) : push_swap.h

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all