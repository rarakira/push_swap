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
}	t_list;

int		push_swap(t_list **start_a, int min_n, int mid_n);
void	clean_all(t_list *start);

void	push_b(t_list **from, t_list **to);
void	push_a(t_list **from, t_list **to);

void	rotate(t_list **start, char list);
void	rev_rotate(t_list **start, char list);

t_list	*get_arguments(int argc, char **argv, int *min_n, int *max_n);
t_list	*init_value(char *num);

int		in_order(t_list *start);
int		closer_to_start(int min, t_list *list);
int		closer_to_start_num(int num, t_list *list);
int		is_last(t_list *list, int n);

int		find_min(t_list *current);
int		find_max(t_list *current);

void	order_list(t_list **list, char list_name);
void	print_list(t_list *start, int min_n, int max_n);
void	print_back(t_list *start, int min_n, int max_n);

#endif
