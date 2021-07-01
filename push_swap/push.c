#include "libft.h"
#include "push_swap.h"

void	push_b(t_list **from, t_list **to)
{
	t_list		*first;
	t_list		*tmp;
	int			min;
	int			max;
	
	tmp = *from;
	*from = (*from)->next;
	tmp->next = NULL;
	if (*to == NULL)
	{
		*to = tmp;
		ft_putendl_fd("pb", 1);
		return;
	}
	max = find_max(*to);
	min = find_min(*to);
	if ((*to)->next)
	{
		if (tmp->num < min || tmp->num > max)
			order_list(to, 'b');
		else
		{
			if (closer_to_start(find_min(*to), *to))
				while (!((*to)->num < tmp->num && (*to)->next->num > tmp->num))
					rotate(to, 'b');
			else
				while (!((*to)->num < tmp->num && (*to)->next->num > tmp->num))
					rev_rotate(to, 'b');
			rotate(to, 'b');
		}
	}
	first = *to;
	*to = tmp;
	(*to)->next = first;
	ft_putendl_fd("pb", 1);
}

void	push_a(t_list **from, t_list **to)
{
	t_list		*first;
	t_list		*tmp;

	tmp = *from;
	if ((*from)->next)
		*from = (*from)->next;
	else
		*from = NULL;
	tmp->next = NULL;
	first = *to;
	*to = tmp;
	(*to)->next = first;
	ft_putendl_fd("pa", 1);
}
