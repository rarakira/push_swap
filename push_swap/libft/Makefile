# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaela <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 14:03:12 by lbaela            #+#    #+#              #
#    Updated: 2021/08/11 22:05:33 by lbaela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFILES =	ft_strlen.c			ft_memset.c			ft_memcpy.c\
			ft_atoi.c			ft_isalpha.c		ft_isdigit.c\
			ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c\
			ft_strncmp.c		get_next_line.c		get_next_line_utils.c

OBJS = $(CFILES:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -I../includes

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $?

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS) $(OBJS_B)
#	@echo "\033[1;38;5;117m*  Libft objects removed\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1;38;5;117m*  libft.a removed\033[0m"

re : fclean all

.PHONY : all clean fclean re bonus
