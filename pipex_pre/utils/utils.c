/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:53:34 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/02 16:14:27 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	err_handler(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_strs(char **strs)
{
	int	index;

	index = -1;
	while (strs[++index] != NULL)
		free(strs[index]);
	free(strs);
}

char	**envp_path(char **envp)
{
	char	**e_path;
	char	*temp;
	int		index;

	index = 0;
	while (envp[index] && !ft_strnstr(envp[index], "PATH=", 5))
		index++;
	temp = envp[index] + 5;
	e_path = ft_split(temp, ':');
	return (e_path);
}

char	*path_finder(char *cmd_head, char **envp)
{
	char	**e_path;
	char	*path;
	char	*temp;
	int		index;

	e_path = envp_path(envp);
	index = -1;
	while (e_path[++index] != NULL)
	{
		temp = ft_strjoin(e_path[index], "/");
		path = ft_strjoin(temp, cmd_head);
		free(temp);
		if (access(path, F_OK) == 0)
			return (path);
		else
			free(path);
	}
	free_strs(e_path);
	return (NULL);
}
