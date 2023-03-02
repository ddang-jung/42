#include "../../include/main.h"
#include "../../include/excute.h"

void	env(t_minishell *m)
{
	t_env	*list;

	list = m->env->next;
	while (list)
	{
		ft_putstr_fd(list->all, 1);
		ft_putstr_fd("\n", 1);
		list = list->next;
	}
}
