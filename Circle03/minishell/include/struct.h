#ifndef STRUCT_H
# define STRUCT_H
# include "../libft/libft.h"

typedef struct s_cmd
{
	char			*str;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_redir
{
	int				type;
	char			*file;
	struct s_redir	*next;
}	t_redir;

typedef struct s_pipe
{
	t_cmd			*cmd_head;
	t_redir			*redir_head;
	int				pipe_cnt;
	char			*str;
	struct s_pipe	*next;
}	t_pipe;

typedef struct s_env
{
	char			*all;
	char			*key;
	char			*val;
	struct s_env	*next;
}	t_env;

typedef struct s_minishell
{
	t_pipe	*head;
	t_env	*env;
	t_env	*senv;
	char	*line;
}	t_minishell;

#endif