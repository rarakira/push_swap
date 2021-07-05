#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"

# include <stdio.h>

typedef struct s_list
{
	int				num;
	struct s_list	*prev;
	struct s_list	*next;
	int				top;
	int				order;
}	t_list;

void	push_swap(t_list **start_a, int step, int parts);
void	clean_all(t_list *start);

int		count_parts(t_list *list, int *parts);
void	mark_ordered(t_list *list);

void	push_b(t_list **from, t_list **to);
void	push_a(t_list **from, t_list **to);

void	rotate(t_list **start, char list);
void	rev_rotate(t_list **start, char list);

t_list	*get_arguments(int argc, char **argv);
t_list	*init_value(char *num);

int		in_order(t_list *start);
int		is_ordered(t_list *start);
int		closer_to_start(int min, t_list *list);
int		closer_to_start_num(int num, t_list *list);
int		is_last(t_list *list, int n);

int		find_min(t_list *current);
int		find_max(t_list *current);
void	init_min_max(t_list *list, int *min, int *max);
int		init_i(int parts);

void	order_list(t_list **list, char list_name);
void	print_list(t_list *start, char *fname);

#endif
