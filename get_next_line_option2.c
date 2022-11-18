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

char *getln(char *buf)
{
  int i;
  char *line;

  i = 0;
  while(buf && buf[i] && buf[i] != '\n')
    i++;
  line = (char*)malloc(sizeof(char) * (i +1));
  if(!line)
    return(NULL);
  i = 0;
  while(buf && buf[i] && buf[i] != '\n')
  {
    line[i] = buf[i];
    i++;
  }
  line[i] = '\0';
  return(line);
}

char *keepbuf(char *buf)
{
  int i;
  int j;
  char *leftover;

  i = 0;
  j = 0;
  while(buf && buf[i] && buf[i] != '\n')
    i++;
  leftover = (char*)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
  if(!leftover)
    return(NULL);
  while(buf && buf[i])
    leftover[j++] = buf[++i];
  leftover[j] = '\0';
  return(leftover);
}

char	*get_next_line(int fd)
{
  char *buf;
  int ret;
  static char *keep;
  char *temp;
  char *line;

  ret = BUFFER_SIZE;
  if (fd < 0 || BUFFER_SIZE <= 0)
      return(NULL);
  buf = (char*)malloc(sizeof(char) * BUFFER_SIZE +1);
  if(!buf)
    return(NULL);
  while (ret > 0)
  {
    ret = read(fd, buf, BUFFER_SIZE);
    if (ret == -1)
      return(NULL);
    buf[ret] = '\0';
    temp = keep;
    keep = ft_strjoin(temp, buf);
    if (temp)
      free(temp);
    free(buf);
    if (ft_strchr(keep, '\n'))
      break;
  }
  line = getln(keep);
  temp = keep;
  keep = keepbuf(temp);
  free(temp);
  if (ret ==0 /*&& keep[0] == 0*/)
  {
    free(keep);
    keep = NULL;
  }

  return(line);
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
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}