#include "push_swap.h"

t_cmd	*create_new_cmd(char *cmd)
{
	t_cmd	*this;

	this = (t_cmd *)malloc(sizeof(t_cmd));
	if (!this)
		return (NULL);
	this->next = NULL;
	this->prev = NULL;
	ft_memset(this->cmd, 0, 4);
	ft_memcpy(this->cmd, cmd, 3);
	return (this);
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
	}
}
