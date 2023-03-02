#include "../include/excute.h"

int	open_error(char *file)
{
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	return (1);
}

int	dir_in(t_excute *e, char *file)
{
	e->in = open(file, O_RDONLY);
	if (e->in < 0)
		return (open_error(file));
	dup2(e->in, STDIN_FILENO);
	close(e->in);
	return (0);
}

void	heredoc(char *eow, char *file)
{
	char	*str;
	int		fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("heredoc_open_error\n", 2);
		return ;
	}
	setting_signal(HDOC);
	while (1)
	{
		str = readline("heredoc> ");
		if (!str)
			return ;
		if (ft_strcmp(str, eow) == 0)
			break ;
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
	free(str);
	close(fd);
	return ;
}

void	parent_init_fork(t_excute *e)
{
	if (e->out == -1)
	{
		if (dup2(e->pipefd[0], STDIN_FILENO) == -1)
			critical_error("dup2_error");
		close(e->pipefd[1]);
		close(e->pipefd[0]);
	}
	else
	{
		dup2(e->origin_in, STDIN_FILENO);
		dup2(e->origin_out, STDOUT_FILENO);
	}
}

void	child_init_fork(t_excute *e)
{
	if (e->out == -1)
	{
		if (dup2(e->pipefd[1], STDOUT_FILENO) == -1)
			critical_error("dup2_error");
		close(e->pipefd[0]);
		close(e->pipefd[1]);
	}
}
