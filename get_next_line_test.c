/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:09:34 by druina            #+#    #+#             */
/*   Updated: 2022/11/15 11:27:41 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_test(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*temp;
	char		*nline;
	int			ret;
	char		*ans;
	//char		*clean;

	if (fd == -1)
		return (NULL);
	if (!temp)
		temp = (char *)malloc(sizeof(char) * 1);
	if (!temp)
		return (NULL);
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0 && (temp == NULL || *temp == '\0'))
			return (NULL);
		buf[ret] = '\0';
	//	clean = temp;
		//free(temp);
		temp = ft_strjoin(temp, buf);
		nline = ft_strchr(temp, '\n');
		if (nline != NULL)
		{
			ans = ft_substr(temp, 0, (ft_strlen(temp) - ft_strlen(nline)) + 1);
			temp = nline + 1;
			return (ans);
		}
	}
	return (NULL);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("bible.txt", O_RDWR);
	while (1)
	{
		str = get_next_line_test(fd);
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}
