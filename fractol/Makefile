CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx 

SRCS = fractol.c libft.c handler_fun.c math.c

OBJS = $(SRCS:.c=.o)

NAME = fractol

all :$(NAME)

$(NAME):$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS):fractol.h

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all