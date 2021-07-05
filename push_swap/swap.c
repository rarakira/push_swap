#include "libft.h"
#include "push_swap.h"

//(void) list;
void	swap(t_list **start, char list)
{
	int		tmp;

	tmp = (*start)->num;
	(*start)->num = (*start)->next->num;
	(*start)->next->num = tmp;
	(*start)->next->order = 1;
	if ((*start)->prev->num < (*start)->num)
		(*start)->order = 2;
	if (list == 'a')
		ft_putendl_fd("sa", 1);
	else
		ft_putendl_fd("sb", 1);
}
