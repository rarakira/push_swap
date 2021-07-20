#include "push_swap.h"

/* Free all elements from the t_list list 'start' */
void	clean_list(t_list *start)
{
	t_list	*current;

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

int	main(int argc, char **argv)
{
	t_list	*start_a;
	t_cmd	*cmds;

	cmds = NULL;
	if (argc == 1)
		return (1);
	start_a = get_arguments(argc, argv);
	if (!start_a)
	{
		ft_putendl_fd("Error", 1);
		return (1);
	}
	if (!in_order(start_a, 'a'))
	{
		mark_ordered(start_a);
		push_swap(&start_a, count_elements(start_a), find_max(start_a), &cmds);
	}
	print_cmds(cmds);
	clean_list(start_a);
	clean_cmds(cmds);
	return (0);
}
