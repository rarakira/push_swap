#include "libft.h"
#include "push_swap.h"

//(void) list;
void	rev_rotate(t_list **start, char list, t_cmd **cmds)
{
	if (*start)
	{
		(*start)->top = 0;
		*start = (*start)->prev;
		(*start)->top = 1;
	}
	if (list == 'a')
		add_cmd("rra", cmds);
	else
		add_cmd("rrb", cmds);
}

void	rotate(t_list **start, char list, t_cmd **cmds)
{
	if (*start)
	{
		(*start)->top = 0;
		*start = (*start)->next;
		(*start)->top = 1;
	}
	if (list == 'a')
		add_cmd("ra", cmds);
	else
		add_cmd("rb", cmds);
}
