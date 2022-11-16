/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:09:34 by druina            #+#    #+#             */
/*   Updated: 2022/11/16 16:30:19 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	char		*temp;
	char		*nline;
	int			ret;
	char		*ans;
	static char	*p;


	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	temp = p;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1 );
	if (!temp)
	{
		temp = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	 }
	if (!temp)
	{
		return (NULL);
	}
	while (1)
	{
		if (!p)
			p = temp;
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0 && (temp == NULL || *temp == '\0'))
		{
			 free(p);
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		temp = ft_strjoin(temp, buf);
		if(!temp)
			return(NULL);
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
		nline = ft_strchr(temp, '\n');
		if (nline != NULL)
		{
			ans = ft_substr(temp, 0, (ft_strlen(temp) - ft_strlen(nline)) + 1);
			p = (char *)malloc(sizeof(char) * ft_strlen(nline));
			ft_strlcpy(p, &temp[ft_strlen(temp) - ft_strlen(nline) + 1],
					ft_strlen(nline + 1));
			free(temp);
			free(buf);
			temp = NULL;
			return (ans);
		}
		if(ret <= 0)
		{
			free(buf);
			return(temp);
		}
	}
	if (buf)
		free(buf);
	if (temp)
		free(temp);

	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*str;

	//int i;
	//i = 0;
	fd = open("bible.txt", O_RDWR);
	while (1)
	{
		str = get_next_line_test(fd);
		printf("%s", str);
		if (str == NULL)
			break ;
		free(str);
	}
	//close(fd);
	return (0);
}
