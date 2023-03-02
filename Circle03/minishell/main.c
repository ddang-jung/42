#include "./include/main.h"

int	g_exit_code;

void	critical_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	main_loop(t_minishell *minishell)
{
	while (1)
	{
		setting_signal(SHELL);
		minishell->line = readline("minishell > ");
		if (minishell->line == NULL)
		{
			ft_putstr_fd("exit\n", 1);
			break ;
		}
		add_history(minishell->line);
		parse(minishell, minishell->env);
		if (g_exit_code != 0)
		{
			free(minishell->line);
			continue ;
		}
		excute(minishell);
		free_line(minishell);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_minishell	minishell;

	if (ac != 1)
		critical_error("Invalid Number of Arguments!");
	init(&minishell, envp);
	main_loop(&minishell);
	free_all(&minishell);
	(void)av;
	return (0);
}
