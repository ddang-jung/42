/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:03:28 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/06 13:15:14 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		index;
	pid_t	pid[argc];

	if (argc < 5)
		err_handler("Invalid Number of Arguments.");
	if (argv[1] == "here_doc")
	{
		fd[0] = here_doc(argv[2]);
		
	}
	// if (pipe(fd) == ERROR)
	// 	err_handler("Function pipe() returned error value.");

	// pid[0] = fork();
	// if (pid[0] == ERROR)
	// 	err_handler("Function fork() returned error value.");
	// else if (pid[0] == 0)
	// 	child_proc(argv, envp, fd);

	// pid[1] = fork();
	// if (pid[1] == ERROR)
	// 	err_handler("Function fork() returned error value.");
	// else if (pid[1] == 0)
	// 	parent_proc(argv, envp, fd);

	// waitpid(pid[0], NULL, 0);
	// waitpid(pid[1], NULL, 0);
	return (0);
}
