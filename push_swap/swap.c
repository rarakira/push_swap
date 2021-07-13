#include "libft.h"
#include "push_swap.h"

/* Swap operation */
void	swap(t_list **start, char list, t_cmd **cmds)
{
	int		tmp;

	tmp = (*start)->num;
	(*start)->num = (*start)->next->num;
	(*start)->next->num = tmp;
	(*start)->order = 1;
	if (list == 'a')
		add_cmd("sa", cmds);
	else
		add_cmd("sb", cmds);
}

/* Checks if there are elements in the list that need swapping */
static int	needs_swap(t_list *list)
{
	t_list	*start;

	start = list;
	while (list)
	{
		if (list->order == 2)
			return (1);
		list = list->next;
		if (list == start)
			break ;
	}
	return (0);
}

/* Checks if the list needs swapping and swaps the elements */
void	do_the_swapping(t_list **list, t_cmd **cmds)
{
	while (needs_swap(*list))
	{
		while ((*list)->order != 2)
			rotate(list, 'a', cmds);
		swap(list, 'a', cmds);
	}
}
