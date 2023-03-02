#include "../../include/main.h"
#include "../../include/excute.h"

void	move_directory(t_minishell *m, char *path, char *cwd)
{
	int	chdir_value;

	chdir_value = chdir(path);
	if (chdir_value == -1)
		print_cd_error(path);
	else
		new_pwd_opwd(m, cwd);
}

void	move_oldpwd(t_minishell *m, char *cwd)
{
	t_env	*node;
	int		chdir_value;

	node = m->senv->next;
	while (ft_strcmp(node->key, "OLDPWD") != 0)
		node = node->next;
	chdir_value = chdir(node->val);
	if (chdir_value == -1)
		print_cd_error(node->val);
	else
	{
		pwd();
		new_pwd_opwd(m, cwd);
	}
}
