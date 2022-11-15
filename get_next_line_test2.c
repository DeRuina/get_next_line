/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:09:34 by druina            #+#    #+#             */
/*   Updated: 2022/11/15 17:07:03 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		ans = NULL;
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0 && (temp == NULL || *temp == '\0'))
			return (NULL);
		buf[ret] = '\0';
	//	clean = temp;
		//free(temp);
		nline = ft_strchr(buf, '\n');
		 if (nline == NULL)
		 {
			temp = ft_strjoin(temp, buf);
			//free(buf);
		 }
		else if (nline != NULL)
		{
			ft_strlcpy(ans,buf,(ft_strlen(buf) - ft_strlen(nline)));
			//free (buf);
			ans = ft_strjoin(temp, ans);
			//free(temp);
			temp = nline +1;
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
	//str = get_next_line_test(fd);
	//printf("%s", str);
	//free(str);
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
