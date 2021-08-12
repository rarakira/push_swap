NAME		=	push_swap

CHECKER		=	checker

SRCS		=	push_swap_utils.c\
				push_forth.c			push_forth_utils.c\
				get_arguments.c			set_index.c\
				find_values.c			order_check.c\
				mark_ordered.c			mark_middle_nums.c\
				push.c					rotate.c\
				swap.c					commands.c\
				clean_up.c				print_list.c

SRCS_M		=	push_swap.c

SRCS_B		=	checker.c				checker_utils.c

OBJS		=	$(SRCS:.c=.o)

OBJ_MAIN		=	$(SRCS_M:.c=.o)

OBJS_B		=	$(SRCS_B:.c=.o)

LIB			=	ft

LIBDIR		=	libft

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

GFLAGS		=	-g

INCLUDES	=	-Iincludes

RM			=	rm -f

DEBUG		=	debug

ARGS		=	-200 -150 -50 0 5 4 100 350 30 46 80 29 90 -2 -5 -1000

all:	lib $(NAME)

bonus:	all $(CHECKER)

$(NAME): ./includes/push_swap.h $(OBJ_MAIN) $(OBJS) $(LIBDIR)/libft.a
		$(CC) $(CFLAGS) $(OBJ_MAIN) $(OBJS) -L$(LIBDIR) -l$(LIB) -o $(NAME)

$(CHECKER): ./includes/push_swap.h $(OBJS_B) $(OBJS) $(LIBDIR)/libft.a
		$(CC) $(CFLAGS) $(OBJS_B) $(OBJS) -L$(LIBDIR) -l$(LIB) -o $(CHECKER)

%.o : %.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

lib:
		$(MAKE) -C $(LIBDIR)

norm:
		@norminette ./*.c $(LIBDIR)/*.c includes/*.h

clean:
		@$(RM) $(OBJS) $(OBJS_B) $(OBJ_MAIN)
		@$(MAKE) clean -C $(LIBDIR)
		@echo "\033[1;38;5;221m*  push_swap objects removed\033[0m"

fclean:	clean
		@$(RM) $(NAME) $(CHECKER) $(DEBUG)
		@$(MAKE) fclean -C $(LIBDIR)
		@echo "\033[1;38;5;221m*  push_swap removed\033[0m"

re:		fclean all

$(DEBUG):
		clang $(CFLAGS) $(GFLAGS) $(INCLUDES) $(SRCS) -L$(LIBDIR) -l$(LIB) -o $(DEBUG)

play: all
		./$(NAME) $(ARGS)

leaks: $(DEBUG)
		./$(DEBUG) $(ARGS)

leaks_valg: $(DEBUG)
		valgrind --leak-check=full ./$(DEBUG) $(ARGS)

.PHONY: all clean fclean re play norm leaks leaks_valg debug bonus
