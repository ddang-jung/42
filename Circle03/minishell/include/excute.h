#ifndef EXCUTE_H
# define EXCUTE_H
# include "main.h"

typedef struct s_excute
{
	int		origin_in;
	int		origin_out;
	int		in;
	int		out;
	int		pipe;
	int		pipefd[2];
	char	**hdoc;

}	t_excute;

typedef struct s_for_execve
{
	char	**path;
	char	*cmd;
	char	**option;	

}	t_for_execve;

void	excute(t_minishell *m);
void	init_excute_heredoc(t_minishell *m, t_excute *e);
void	ft_execve(t_minishell *m, t_pipe *p);

int		ft_strcmp(char *s1, char *s2);
int		open_error(char *file);
int		init_rid(t_pipe *p, t_excute *e);
int		dir_in(t_excute *e, char *file);
int		dir_out(t_excute *e, char *file, int dir);
int		check_old_env(t_minishell *m, char *str);
int		check_built_or_execve(t_pipe *p, int count);
char	*ft_strjoin2(char *s1, char *s2);
char	*init_key_and_value(char *str, int type);
char	*check_path(char *cmd, char **path);
char	**get_path(t_minishell *m);
void	heredoc(char *eow, char *file);
void	sorting_env(t_minishell *m);
void	new_put_in_env(t_minishell *m, char *str);
void	remove_unset_senv(t_minishell *m, char *src);
void	remove_unset_env(t_minishell *m, char *src);
void	free_key_value(char *key, char *value);
void	old_put_in_env(t_minishell *m, char *str);
void	parent_init_fork(t_excute *e);
void	child_init_fork(t_excute *e);
void	built_in_exe(t_minishell *m, t_pipe *p, char *cmd);
void	only_excute(t_minishell *m, t_pipe *p, t_excute *e);
void	move_directory(t_minishell *m, char *path, char *cwd);
void	move_oldpwd(t_minishell *m, char *cwd);
void	print_cd_error(char *str);
void	new_pwd_opwd(t_minishell *m, char *cwd);
void	unlink_all(void);

void	exe(t_minishell *m, t_pipe *p);
void	export(t_minishell *m, t_pipe *p);
void	env(t_minishell *m);
void	pwd(void);
void	unset(t_minishell *m, t_pipe *p);
void	echo(t_minishell *m, t_pipe *p);
void	cd(t_minishell *m, t_pipe *p);
void	ft_exit(t_pipe *p);

#endif