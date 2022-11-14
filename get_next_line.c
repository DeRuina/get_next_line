/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:26:23 by druina            #+#    #+#             */
/*   Updated: 2022/11/14 12:36:42 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_(int fd)
{
	char buf[BUFFER_SIZE +1];
	int ret;
	static char *temp;
	char *line;

	if (fd == -1)
		return(NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	temp = buf;

	// if (ft_strchr(temp, '\n')!= NULL)
	// {
	// 	line =
	// }

	return(NULL);
}
