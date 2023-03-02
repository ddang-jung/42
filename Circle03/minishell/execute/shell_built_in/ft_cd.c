#include "../../include/main.h"
#include "../../include/excute.h"

int	g_exit_code;

void	print_cd_error(char *str)
{
	ft_putstr_fd(" cd: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": Not a directory\n", 2);
	g_exit_code = 1;
}

void	new_pwd_opwd(t_minishell *m, char *cwd)
{
	char	*old;
	char	*new;

	if (cwd == NULL)
		cwd = ft_strdup("");
	old = ft_strjoin("OLDPWD=", cwd);
	free(cwd);
	if (check_old_env(m, old) == 1)
		old_put_in_env(m, old);
	else
		new_put_in_env(m, old);
	new = ft_strjoin("PWD=", getcwd(NULL, 0));
	if (check_old_env(m, new) == 1)
		old_put_in_env(m, new);
	else
		new_put_in_env(m, new);
}

static t_cmd	*init_position(t_pipe *p)
{
	t_cmd	*node;

	node = p->cmd_head->next;
	while (node)
	{
		if (ft_strcmp(node->str, "cd") == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	cd(t_minishell *m, t_pipe *p)
{
	int		chdir_value;
	char	*path;
	char	*cwd;
	t_cmd	*node;

	node = init_position(p);
	path = getenv("HOME");
	cwd = getcwd(NULL, 0);
	if (node->next == NULL || node->next->str[0] == '~' || \
		ft_strcmp("", node->next->str) == 0)
	{
		move_directory(m, path, cwd);
		return ;
	}
	if (node->next->str[0] == '-')
	{
		move_oldpwd(m, cwd);
		return ;
	}
	chdir_value = chdir(node->next->str);
	if (chdir_value == -1)
		print_cd_error(node->next->str);
	else
		new_pwd_opwd(m, cwd);
}
