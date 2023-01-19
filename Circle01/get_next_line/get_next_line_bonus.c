/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:41:26 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/09/14 15:11:57 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *save)
{
	char	buf[BUFFER_SIZE + 1];
	int		size;

	size = 1;
	while (size > 0 && newline_index(save) == -1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (save);
		buf[size] = '\0';
		save = ft_strjoin(save, buf);
	}
	return (save);
}

char	*no_nl(char *save)
{
	char	*rst;
	int		index;

	rst = (char *)malloc(sizeof(char) * (ft_strlen(save) + 1));
	if (!rst)
		return (NULL);
	index = -1;
	while (save[++index])
		rst[index] = save[index];
	rst[index] = '\0';
	return (rst);
}

char	*cut_till_newline(char *save, int nl_index)
{
	char	*rst;

	if (*save == '\0')
		return (NULL);
	if (nl_index == -1)
		rst = no_nl(save);
	else
	{
		rst = (char *)malloc(sizeof(char) * (nl_index + 2));
		if (!rst)
			return (NULL);
		rst[nl_index + 1] = '\0';
		while (nl_index > -1)
		{
			rst[nl_index] = save[nl_index];
			nl_index--;
		}
	}
	return (rst);
}

static char	*save_snuff(char *save, int nl_index)
{
	char	*snuff;
	int		index;

	if (nl_index == -1 || !save[nl_index + 1])
	{
		free(save);
		return (NULL);
	}
	snuff = (char *)malloc(sizeof(char) * (ft_strlen(save) - nl_index));
	index = 0;
	while (save[nl_index + index + 1])
	{
		snuff[index] = save[nl_index + index + 1];
		index++;
	}
	snuff[index] = '\0';
	free(save);
	return (snuff);
}

char	*get_next_line(int fd)
{
	static char	*save[49152];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	save[fd] = read_file(fd, save[fd]);
	if (!(save[fd]))
		return (NULL);
	line = cut_till_newline(save[fd], newline_index(save[fd]));
	save[fd] = save_snuff(save[fd], newline_index(save[fd]));
	return (line);
}
