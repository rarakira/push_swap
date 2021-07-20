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
	int				index;
}	t_list;

typedef struct s_cmd
{
	int				print;
	struct s_cmd	*prev;
	struct s_cmd	*next;
	char			cmd[4];
}	t_cmd;

void	push_swap(t_list **start_a, int n_el, int max_n, t_cmd **cmds);
void	push_forth(t_list **start_a, t_list **start_b, t_cmd **cmds);
int		find_closer_number(t_list **src, t_list **dst);
void	clean_list(t_list *start);

void	add_cmd(char *cmd, t_cmd **start);
void	print_cmds(t_cmd *cmds);

int		count_elements(t_list *list);
void	mark_ordered(t_list *list);
void	mark_middle_nums(t_list *list);
void	set_index(t_list *list, int min);

void	push_b(t_list **from, t_list **to, t_cmd **cmds);
void	push_a(t_list **from, t_list **to, t_cmd **cmds);

void	rotate(t_list **start, char list, t_cmd **cmds);
void	rev_rotate(t_list **start, char list, t_cmd **cmds);

void	swap(t_list **start, char list, t_cmd **cmds);
void	do_the_swapping(t_list **list, t_cmd **cmds);

t_list	*get_arguments(int argc, char **argv);

int		in_order(t_list *start, char list_name);
int		is_ordered(t_list *start);
int		closer_to_start(int num, t_list *list, char list_name);
int		count_steps(t_list *list, char list_name, int num, int type);

int		find_min(t_list *current);
int		find_max(t_list *current);
void	init_static_values(t_list *list, int *min, int *max);
int		count_larger_than(t_list *start_a, int threshold);

void	order_list(t_list **list, char list_name, t_cmd **cmds);
void	print_list(t_list *start, char *title);

#endif
