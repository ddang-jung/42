#include "include/main.h"

int	g_exit_code;

void	sig_handle_shell(int signum)
{
	if (signum == SIGINT)
	{
		//rl_replace_line("", 1);
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_redisplay();
		g_exit_code = 1;
	}
}

void	sigint_handle_heredoc(int signum)
{
	if (signum == SIGINT)
	{
		close(STDIN_FILENO);
		write(1, "\n", 1);
	}
	g_exit_code = 1;
}

void	sig_handle_fork(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_exit_code = 130;
	}
	if (signum == SIGQUIT)
	{
		ft_putstr_fd("Quit : 3\n", STDERR_FILENO);
		g_exit_code = 131;
	}
}

void	setting_signal(int status)
{
	if (status == SHELL)
	{
		signal(SIGINT, sig_handle_shell);
		signal(SIGQUIT, SIG_IGN);
	}
	if (status == HDOC)
	{
		signal(SIGINT, sigint_handle_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
	if (status == FORK)
	{
		signal(SIGINT, sig_handle_fork);
		signal(SIGQUIT, sig_handle_fork);
	}
}
