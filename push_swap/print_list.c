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

static void	print_line(void)
{
	ft_putstr_fd(" --------------------------------------- ", 1);
	ft_putendl_fd(" -------------------------------------- ", 1);
}

void	print_stacks(t_list *start_a, t_list *start_b)
{
	int	first_r;

	first_r = 1;
	while ((start_a && !start_a->top) || (start_b && !start_b->top) || first_r)
	{
		if (start_a && (!start_a->top || first_r))
		{
			ft_putstr_fd("|\t\t", 1);
			ft_putnbr_fd(start_a->num, 1);
			ft_putstr_fd("\t\t\t|", 1);
			start_a = start_a->next;
		}
		else
			ft_putstr_fd("|\t\t\t\t\t|", 1);
		if (start_b && (!start_b->top || first_r))
		{
			ft_putstr_fd("|\t\t", 1);
			ft_putnbr_fd(start_b->num, 1);
			ft_putendl_fd("\t\t\t|", 1);
			start_b = start_b->next;
		}
		else
			ft_putendl_fd("|\t\t\t\t\t|", 1);
		first_r = 0;
	}
}

/* Prints out 2 lists with custom title side by side */
void	print_lists(t_list *start_a, t_list *start_b, char *title)
{
	ft_putstr_fd("\033[1;48;5;235m\n\n======= ", 1);
	ft_putendl_fd(title, 1);
	print_line();
	ft_putendl_fd("|\t\tStack A\t\t\t||\t\tStack B\t\t\t|", 1);
	print_line();
	print_stacks(start_a, start_b);
	print_line();
	ft_putendl_fd("\033[0m", 1);
}
