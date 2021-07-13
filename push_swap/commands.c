#include "push_swap.h"

t_cmd	*create_new_cmd(char *cmd)
{
	t_cmd	*this;

	this = (t_cmd *)malloc(sizeof(t_cmd));
	if (!this)
		return (NULL);
	this->next = NULL;
	this->prev = NULL;
	this->print = 1;
	ft_memset(this->cmd, 0, 4);
	ft_memcpy(this->cmd, cmd, 3);
	return (this);
}

void	replace_cmd(t_cmd *last, char *cmd_curr, char *cmd_prev, char *cmd_new)
{
	t_cmd	*prev;

	prev = last->prev;
	if (!ft_strncmp(cmd_curr, last->cmd, 3))
	{
		while (!prev->print || !ft_strncmp(cmd_new, prev->cmd, 4))
			prev = prev->prev;
		if (!ft_strncmp(cmd_prev, prev->cmd, 3))
		{
			ft_memcpy(prev->cmd, cmd_new, 3);
			last->print = 0;
			return ;
		}
	}
}

void	update_cmds(t_cmd *last)
{
	if (!ft_strncmp("pb", last->cmd, 3) || !ft_strncmp("pa", last->cmd, 3)
		|| !ft_strncmp("sa", last->cmd, 3))
		return ;
	if (!ft_strncmp("rb", last->cmd, 3))
		replace_cmd(last, "rb", "ra", "rr");
	if (!ft_strncmp("ra", last->cmd, 3))
		replace_cmd(last, "ra", "rb", "rr");
	if (!ft_strncmp("rrb", last->cmd, 3))
		replace_cmd(last, "rrb", "rra", "rrr");
	if (!ft_strncmp("rra", last->cmd, 3))
		replace_cmd(last, "rra", "rrb", "rrr");
}

void	add_cmd(char *cmd, t_cmd **start)
{
	t_cmd	*last;
	t_cmd	*tmp;

	last = *start;
	if (!(*start))
		*start = create_new_cmd(cmd);
	else
	{
		while (last->next)
			last = last->next;
		last->next = create_new_cmd(cmd);
		tmp = last;
		last = last->next;
		last->prev = tmp;
		update_cmds(last);
	}
}
