#include "../include/main.h"

t_env	*new_env(char *str)
{
	t_env	*new;
	int		i;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		critical_error("Function malloc() Error.");
	new->all = ft_strdup(str);
	i = -1;
	while (str[++i])
		if (str[i] == '=')
			break ;
	new->key = ft_substr(str, 0, i);
	new->val = ft_substr(str, i + 1, ft_strlen(str));
	new->next = NULL;
	return (new);
}

void	set_env(t_minishell *minishell, char **envp)
{
	t_env	*node;
	t_env	*s_node;
	int		i;

	node = minishell->env;
	s_node = minishell->senv;
	i = -1;
	while (envp[++i] != NULL)
	{
		node->next = new_env(envp[i]);
		node = node->next;
		s_node->next = new_env(envp[i]);
		s_node = s_node->next;
	}
}
