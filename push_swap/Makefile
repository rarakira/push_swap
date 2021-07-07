NAME		= push_swap

SRCS		=	main.c					push_swap.c\
				get_arguments.c			print_list.c\
				find_values.c			order_check.c\
				mark_ordered.c			mark_middle_nums.c\
				push.c					rotate.c\
				swap.c

OBJS		= $(SRCS:.c=.o)

LIB			= ft

LIBDIR		= libft

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

GFLAGS		= -g -fsanitize=address

INCLUDES	= -Iincludes

RM			= rm -f

DEBUG		= debug

ARGS		= -200 -150 -50 0 5 4 100 350 30 46 80 29 90 -2 -5 -1000

all:	lib $(NAME)

$(NAME): ./includes/push_swap.h $(OBJS) $(LIBDIR)/libft.a
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -l$(LIB) -o $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

lib:
		$(MAKE) -C $(LIBDIR)

norm:
	@norminette ./*.c $(LIBDIR)/*.c includes/*.h

clean:
		@$(RM) $(OBJS)
		@$(MAKE) clean -C $(LIBDIR)
#		@echo "*  Push_swap objects removed"

fclean:	clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(LIBDIR)

re:		fclean all

$(DEBUG):
		$(CC) $(CFLAGS) $(INCLUDES) $(GFLAGS) $(SRCS) -L$(LIBDIR) -l$(LIB) -o $(DEBUG)

play: all
		./$(NAME) $(ARGS)

leaks: all $(DEBUG)
		./$(DEBUG) $(ARGS)

leaks_v: all
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

.PHONY: all clean fclean re play norm leaks leaks_v debug
