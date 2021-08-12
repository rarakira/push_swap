#include "push_swap.h"

/* Free all elements from the t_list list 'start' */
void	clean_list(t_list *start)
{
	t_list	*current;

	if (!start)
		return ;
	if (start->prev)
	{
		current = start->prev;
		current->next = NULL;
	}
	while (start)
	{
		current = start;
		start = start->next;
		free(current);
		if (!start)
			break ;
	}
}

/* Free all command elements from the t_cmd list 'start' */
void	clean_cmds(t_cmd *start)
{
	t_cmd	*current;

	if (start && start->prev)
	{
		current = start->prev;
		current->next = NULL;
	}
	while (start)
	{
		current = start;
		start = start->next;
		free(current);
		if (!start)
			break ;
	}
}
