#include "libft.h"
#include "push_swap.h"

//(void) list;
void	rev_rotate(t_list **start, char list)
{
	(*start)->top = 0;
	*start = (*start)->prev;
	(*start)->top = 1;
	if (list == 'a')
		ft_putendl_fd("rra", 1);
	else
		ft_putendl_fd("rrb", 1);
}

void	rotate(t_list **start, char list)
{
	(*start)->top = 0;
	*start = (*start)->next;
	(*start)->top = 1;
	if (list == 'a')
		ft_putendl_fd("ra", 1);
	else
		ft_putendl_fd("rb", 1);
}
