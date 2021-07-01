NAME		= push_swap

SRCS		=	main.c			get_arguments.c			order_check.c\
				push.c			rotate.c				swap.c

OBJS		= $(SRCS:.c=.o)

LIB			= ft

LIBDIR		= libft

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -Iincludes

RM			= rm -f

all:	lib $(NAME)

$(NAME): $(OBJS) $(LIBDIR)/libft.a
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -l$(LIB) -o $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

lib:
		@$(MAKE) -C $(LIBDIR)

norm:
	@norminette ./*.c $(LIBDIR)/*.c includes/*.h

clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C $(LIBDIR)

fclean:	clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(LIBDIR)

re:		fclean all

play: all
		@./test

leaks: all
		@valgrind --leak-check=full --show-leak-kinds=all ./test

.PHONY: all clean fclean re test play norm leaks
