#include "push_swap.h"

typedef struct s_cmd
{
	int				order;
	struct s_instr	*prev;
	struct s_instr	*next;
	char			cmd[4];
}	t_cmd;

t_cmd	*create_new(t_cmd *start, char *cmd)
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
