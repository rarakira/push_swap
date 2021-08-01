NAME		= push_swap

SRCS		=	main.c					push_swap.c\
				push_forth.c			push_forth_utils.c\
				get_arguments.c			set_index.c\
				find_values.c			order_check.c\
				mark_ordered.c			mark_middle_nums.c\
				push.c					rotate.c\
				swap.c					commands.c\
				print_list.c

OBJS		= $(SRCS:.c=.o)

LIB			= ft

LIBDIR		= libft

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

GFLAGS		= -fsanitize=address -g

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
		@echo "\033[1;38;5;221m*  push_swap objects removed\033[0m"

fclean:	clean
		@$(RM) $(NAME) debug
		@$(MAKE) fclean -C $(LIBDIR)
		@echo "\033[1;38;5;221m*  push_swap removed\033[0m"

re:		fclean all

$(DEBUG):
		clang $(CFLAGS) $(GFLAGS) $(INCLUDES) $(SRCS) -L$(LIBDIR) -l$(LIB) -o $(DEBUG)

play: all
		./$(NAME) $(ARGS)

leaks: $(DEBUG)
		./$(DEBUG) $(ARGS)

leaks_valg: all
		valgrind --leak-check=full ./$(NAME) $(ARGS)

.PHONY: all clean fclean re play norm leaks leaks_valg debug
