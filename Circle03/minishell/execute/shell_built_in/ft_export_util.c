#include "../../include/main.h"
#include "../../include/excute.h"

char	*init_key_and_value(char *str, int type)
{
	int		i;
	size_t	cnt;

	cnt = ft_strlen(str);
	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	if (type == 'k')
		return (ft_substr(str, 0, i));
	else if (type == 'v' && str[i] == '=')
		return (ft_substr(str, i + 1, cnt));
	else
		return (NULL);
}

static t_env	*new_env(char *str)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		critical_error("Function malloc() Error.");
	new->all = ft_strdup(str);
	new->key = init_key_and_value(str, 'k');
	new->val = init_key_and_value(str, 'v');
	new->next = NULL;
	return (new);
}

void	new_put_in_env(t_minishell *m, char *str)
{
	t_env	*temp;
	t_env	*temp2;
	t_env	*last_senv;
	t_env	*last_env;

	temp = new_env(str);
	temp2 = new_env(str);
	last_env = ft_lstlast(m->env);
	last_senv = ft_lstlast(m->senv);
	if (temp->val != NULL)
	{
		last_env->next = temp;
		temp->next = NULL;
	}
	last_senv->next = temp2;
	temp->next = NULL;
}

void	old_put_in_env(t_minishell *m, char *str)
{
	t_env	*node;
	char	*key;
	char	*value;

	key = init_key_and_value(str, 'k');
	value = init_key_and_value(str, 'v');
	node = m->senv->next;
	while (ft_strcmp(node->key, key) != 0)
		node = node->next;
	if (value != NULL)
	{
		remove_unset_env(m, key);
		remove_unset_senv(m, key);
		new_put_in_env(m, str);
	}
}

int	check_old_env(t_minishell *m, char *str)
{
	t_env	*list;
	char	*key;

	list = m->senv->next;
	key = init_key_and_value(str, 'k');
	while (list)
	{
		if (ft_strcmp(list->key, key) == 0)
		{
			free(key);
			return (1);
		}
		list = list->next;
	}
	if (key != NULL)
		free(key);
	return (0);
}
