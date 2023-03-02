#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include "struct.h"
# include "excute.h"

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ERROR -1

extern int	g_exit_code;

typedef enum e_type
{
	HEAD,
	RID_IN,
	RID_OUT,
	HEREDOC,
	APPEND,
}	t_type;

typedef enum e_status
{
	SHELL,
	HDOC,
	FORK
}	t_status;

// TODO UTILS
void	critical_error(char *message);
char	*ft_strjoin3(char *s1, char *s2);

// TODO INIT
void	init(t_minishell *minishell, char **envp);
t_redir	*init_redir(void);
t_cmd	*init_cmd(void);
t_env	*init_env(void);

// TODO ENV
void	sorting_env(t_minishell *m);
void	set_env(t_minishell *minishell, char **envp);

// TODO PARSE
void	parse(t_minishell *minishell, t_env *env);
void	interpreter(t_cmd *head, t_env *env);
int		is_interpreter(char flag, char c);
char	*ft_strctrim(char const *s, char const c);
char	check_quote(char flag, char c);
void	tokenizer(t_redir *redir_head, t_cmd *cmd_head, char *str);
int		check_syntax(char *line);
char	*ft_getenv(char *sub, t_env *env);
int		get_type(char *str, int *i);
char	*get_file(char *str, int *i, int *loc);
int		only_pipe(char *line, int i, int *loc);

// TODO SYNTAX
int		check_only_space(char *line);
int		check_only_pipe(char *line);
int		check_only_pipe2(char *line);
int		check_unclosed_quote(char *line);
int		check_unexpected_token(char *line);

// TODO signal
void	setting_signal(int status);
void	sigint_handle_heredoc(int signum);
void	sig_handle_fork(int signum);

// TODO FREE
void	free_all(t_minishell *minishell);
void	free_line(t_minishell *minishell);

#endif