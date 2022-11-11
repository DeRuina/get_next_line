/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:09:34 by druina            #+#    #+#             */
/*   Updated: 2022/11/11 15:16:30 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE +1];
	int		ret;
	//int newline;

	if (fd == -1)
		return (NULL);


	while(1)
	{
	ret = read(fd, buf, BUFFER_SIZE);

	if (ret < BUFFER_SIZE)
	{
		buf[ret] = '\0';
		printf("%s\n", buf);
		printf("%d\n", ret);
		break;
	}
	else
		{
			buf[ret] = '\0';
			printf("%s\n", buf);
		}
printf("%d\n", ret);
	}
	printf("%d\n", 3);
	return (NULL);

}

int	main(void)
{
	char *str;
	int	fd;
	fd = open("test.txt", O_RDWR);
	str = get_next_line(fd);
	 printf("%s\n", get_next_line(fd));
	close(fd);
		return (0);
}
