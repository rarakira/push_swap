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

typedef struct s_cmd
{
	struct s_cmd	*prev;
	struct s_cmd	*next;
	char			cmd[4];
}	t_cmd;

void	push_swap(t_list **start_a, int step, int parts, t_cmd **cmds);
void	clean_list(t_list *start);

void	add_cmd(char *cmd, t_cmd **start);

int		count_parts(t_list *list, int *parts);
void	mark_ordered(t_list *list);
void	mark_middle_nums(t_list *list);

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

int		find_min(t_list *current);
int		find_max(t_list *current);
void	init_min_max(t_list *list, int *min, int *max);
int		init_i(int parts);

void	order_list(t_list **list, char list_name, t_cmd **cmds);
void	print_list(t_list *start, char *title);

#endif
