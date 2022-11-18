/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:42:40 by druina            #+#    #+#             */
/*   Updated: 2022/11/18 17:44:52 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*getln(char *buf)
{
	int		i;
	char	*line;
	int		len;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	len = i + 1;
	i = 0;
	while (i < len)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*keepbuf(char *buf)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	j = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	leftover = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (!leftover)
		return (NULL);
	while (buf[i] != '\0')
		leftover[j++] = buf[++i];
	leftover[j] = '\0';
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*keep;
	char		*temp;
	char		*line;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1 || (ret == 0 && keep == NULL))
			return (NULL);
		buf[ret] = '\0';
		temp = keep;
		keep = ft_strjoin(temp, buf);
		if (temp)
			free(temp);
		if (ft_strchr(keep, '\n'))
			break ;
	}
	line = getln(keep);
	if (ret == 0 && !*keep)
	{
		if (temp)
			free(temp);
		if (keep)
			free(keep);
		keep = NULL;
		return (NULL);
	}
	temp = keep;
	keep = keepbuf(temp);
	free(temp);
	return (line);
}
