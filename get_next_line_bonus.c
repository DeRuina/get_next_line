/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:10:40 by druina            #+#    #+#             */
/*   Updated: 2022/11/21 14:47:34 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	cleanit(int ret, char *keep, char *temp)
{
	if (ret == 0 && !*keep)
	{
		if (temp)
			free(temp);
		if (keep)
			free(keep);
		keep = NULL;
		return (0);
	}
	return (1);
}

char	*getln(int ret, char *keep, char *temp)
{
	int		i;
	char	*line;
	int		len;

	i = 0;
	while (keep[i] != '\0' && keep[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	len = i + 1;
	i = 0;
	while (i < len)
	{
		line[i] = keep[i];
		i++;
	}
	line[i] = '\0';
	if (cleanit(ret, keep, temp) == 0)
		return (NULL);
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

char	*keepandfree(char *keep, char *buf, char *temp)
{
	keep = ft_strjoin(temp, buf);
	if (temp)
		free(temp);
	return (keep);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE +1];
	int			ret;
	static char	*keep[10240];
	char		*temp;
	char		*line;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1 || (ret == 0 && keep[fd] == NULL))
			return (NULL);
		buf[ret] = '\0';
		temp = keep[fd];
		keep[fd] = keepandfree(keep[fd], buf, temp);
		if (ft_strchr(keep[fd], '\n'))
			break ;
	}
	line = getln(ret, keep[fd], temp);
	temp = keep[fd];
	keep[fd] = keepbuf(temp);
	free(temp);
	return (line);
}
