/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:09:34 by druina            #+#    #+#             */
/*   Updated: 2022/11/14 16:59:20 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_test(int fd)
{
	 char	buf[BUFFER_SIZE +1];
	static char *temp;
	char *line;
	int ret;
	char *answer;

	if (fd == -1)
		return (NULL);

	if(!temp)
		temp = (char*)malloc(sizeof(char) * 1);
	if (!temp)
		return(NULL);
	while(1)
	{

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < BUFFER_SIZE)
	{
		buf[ret] = '\0';

		break;
	}
	else
		buf[ret] = '\0';
	temp = ft_strjoin(temp, buf);

	line = ft_strchr(temp, '\n');
	if (line != NULL)
	{
		answer = ft_substr(temp, 0, ft_strlen(temp) - ft_strlen(line));
		temp = line +1;
		return(answer);
	}
	free(temp);
	free(line);
	//printf("%s\n", line);
	}
	//printf(" this is the end: %s\n", temp);
	return (NULL);

}

int	main(void)
{
	char *str;
	char *str2;
	int	fd;
	fd = open("test.txt", O_RDWR);
	str = get_next_line_test(fd);
	printf("%s\n", str);
	//free(str);
	str2 = get_next_line_test(fd);
	printf("%s\n", str2);
	//free(str2);
	close(fd);
		return (0);
}
