#include "push_swap.h"

/* Prints out calculated commands from the list */
void	print_cmds(t_cmd *cmds)
{
	t_cmd	*tmp;

	tmp = cmds;
	while (tmp)
	{
		if (tmp->print)
			ft_putendl_fd(tmp->cmd, 1);
		tmp = tmp->next;
	}
}

/* Prints out passed list with custom title */
void	print_list(t_list *start, char *title)
{
	printf("\n-------\nPRINT LIST [%s]\n\n", title);
	while (start)
	{
		//printf("%d -> %d -> %d\n", start->num, start->next->num, start->next->next->num);
		printf("%d (o:%d)\n", start->num, start->order);
		start = start->next;
		//printf("%d is top :: %d\n", start->num, start->top);
		if (start->top)
			break ;
	}
	printf("\n-------\n\n");
}
