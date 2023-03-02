#include "../include/main.h"
#include "../include/excute.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		di;
	int		si;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	di = -1;
	while (s1[++di] != '\0')
		dest[di] = s1[di];
	si = 0;
	while (s2[si] != '\0')
		dest[di++] = s2[si++];
	dest[di] = '\0';
	free (s1);
	s1 = NULL;
	return (dest);
}

char	**get_path(t_minishell *m)
{
	char	**dest;
	t_env	*node;

	node = m->env->next;
	while (node)
	{
		if (ft_strcmp(node->key, "PATH") == 0)
			break ;
		node = node->next;
	}
	if (!node)
		return (NULL);
	dest = ft_split(node->val, ':');
	if (dest == NULL)
		critical_error("path_split_error");
	return (dest);
}

char	*check_path(char *cmd, char **path)
{
	char	*tcmd;
	char	*temp;
	int		acc;
	int		i;

	acc = access(cmd, X_OK);
	if (acc == 0)
		return (cmd);
	tcmd = ft_strjoin("/", cmd);
	if (tcmd == NULL)
		critical_error("strjoin");
	i = 0;
	while (path[i] != NULL)
	{
		temp = ft_strjoin(path[i], tcmd);
		acc = access(temp, X_OK);
		if (acc == 0)
		{
			free(tcmd);
			return (temp);
		}
		free(temp);
		i++;
	}
	return (NULL);
}
