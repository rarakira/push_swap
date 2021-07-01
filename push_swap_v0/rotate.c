#include "libft.h"
#include "push_swap.h"

void	rev_rotate(t_list **start, char list)
{
	t_list		*new_first;
	t_list		*tmp;

	new_first = *start;
	while (new_first->next->next)
		new_first = new_first->next;
	tmp = new_first;
	new_first = new_first->next;
	tmp->next = NULL;
	new_first->next = *start;
	*start = new_first;
	if (list == 'a')
		ft_putendl_fd("rra", 1);
	else
		ft_putendl_fd("rrb", 1);
}

void	rotate(t_list **start, char list)
{
	t_list		*first;
	t_list		*tmp;

	first = *start;
	*start = first->next;
	tmp = *start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	if (list == 'a')
		ft_putendl_fd("ra", 1);
	else
		ft_putendl_fd("rb", 1);
}
