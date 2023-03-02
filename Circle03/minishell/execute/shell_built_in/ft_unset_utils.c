#include "../../include/main.h"
#include "../../include/excute.h"

void	free_list(t_env *env)
{
	if (env->all != NULL)
		free(env->all);
	if (env->key != NULL)
		free(env->key);
}

void	remove_unset_env(t_minishell *m, char *src)
{
	t_env	*list;
	t_env	*front;

	front = m->env;
	list = m->env->next;
	while (list)
	{
		if (ft_strcmp(list->key, src) == 0)
		{
			front->next = list->next;
			return ;
		}
		front = front->next;
		list = list->next;
	}
}

void	remove_unset_senv(t_minishell *m, char *src)
{
	t_env	*list;
	t_env	*front;

	front = m->senv;
	list = m->senv->next;
	while (list)
	{
		if (ft_strcmp(list->key, src) == 0)
		{
			front->next = list->next;
			free_list(list);
			return ;
		}
		front = front->next;
		list = list->next;
	}
}

void	free_key_value(char *key, char *value)
{
	if (key != NULL)
		free(key);
	if (key != NULL)
		free(value);
}
