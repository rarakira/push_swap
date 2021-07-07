#include "libft.h"
#include "push_swap.h"

/* Swap operation */
void	swap(t_list **start, char list)
{
	int		tmp;

	tmp = (*start)->num;
	(*start)->num = (*start)->next->num;
	(*start)->next->num = tmp;
	(*start)->order = 1;
	if (list == 'a')
		ft_putendl_fd("sa", 1);
	else
		ft_putendl_fd("sb", 1);
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
void	do_the_swapping(t_list **list)
{
	while (needs_swap(*list))
	{
		while ((*list)->order != 2)
			rotate(list, 'a');
		swap(list, 'a');
	}
}
