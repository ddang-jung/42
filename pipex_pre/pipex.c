/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:56:26 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/06 13:16:02 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	run_command(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(cmd, ' ');
	path = path_finder(cmds[0], envp);
	if (path == NULL)
		err_handler("Command not found.");
	if (execve(path, cmds, envp) == ERROR)
		err_handler("Function execve() returned error value.");
	free_strs(cmds);
	free(path);
}

void	child_proc(char **argv, char **envp, int fd[2])
{
	int	infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == ERROR)
		err_handler("Function open(infile) returned error value.");
	dup2(fd[1], STDOUT);
	dup2(infile_fd, STDIN);
	close(fd[0]);
	run_command(argv[2], envp);
}

void	parent_proc(char **argv, char **envp, int fd[2])
{
	int	outfile_fd;

	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == ERROR)
		err_handler("Function open(outfile) returned error value.");
	dup2(fd[0], STDIN);
	dup2(outfile_fd, STDOUT);
	close(fd[1]);
	run_command(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	if (argc != 5)
		err_handler("Invalid Number of Arguments.");
	if (pipe(fd) == ERROR)
		err_handler("Function pipe() returned error value.");

	pid[0] = fork();
	if (pid[0] == ERROR)
		err_handler("Function fork() returned error value.");
	else if (pid[0] == 0)
		child_proc(argv, envp, fd);

	pid[1] = fork();
	if (pid[1] == ERROR)
		err_handler("Function fork() returned error value.");
	else if (pid[1] == 0)
		parent_proc(argv, envp, fd);

	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}
