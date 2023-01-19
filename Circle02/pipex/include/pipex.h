/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:56:47 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/02 19:22:53 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef enum e_status
{
	ERROR = -1,
	STDIN,
	STDOUT,
}	t_status;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strndup(const char *s1, int n);
size_t	ft_strlen(const char *s);

void	err_handler(const char *str);
void	free_strs(char **strs);
char	*path_finder(char *cmd_head, char **envp);

#endif