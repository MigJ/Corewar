/*
** get_next_line.c for get_next_line in /home/detroy_j/Documents/delivery/CPE_2016_getnextline
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Dec 21 15:09:00 2016 detroy_j
** Last update Sat Apr  1 01:20:14 2017 Joubert Miguel
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"

static char	*remalloc(char *str, size_t len)
{
  size_t	i;
  char	*res;

  i = -1;
  res = my_memset(len + READ_SIZE + 1 * 10);
  while (++i < len)
    res[i] = str[i];
  res[i] = 0;
  free(str);
  return (res);
}

static char	my_read(const int fd)
{
  static char	buffer[READ_SIZE + 1];
  static char	*p;
  static size_t	bytes_read = 0;
  char	c;

  if (bytes_read == 0)
    {
      if ((bytes_read = read(fd, buffer, READ_SIZE)) < 1)
	return (-1);
      p = (char *) &buffer;
      if (bytes_read == 0)
	return (0);
    }
  c = *p;
  p++;
  bytes_read--;
  return (c);
}

char	*get_next_line(const int fd)
{
  size_t	i;
  char	ch;
  char	*line;

  if (fd < 0)
    return (NULL);
  i = 0;
  line = my_memset(READ_SIZE + 1 * 10);
  if ((ch = my_read(fd)) == -1)
    return (NULL);
  while (ch != '\n' && ch != '\0')
    {
      line[i++] = ch;
      ch = my_read(fd);
      if (ch == -1)
	{
	  (i % (READ_SIZE + 1) == 0) ? line = remalloc(line, i) : 0;
	  break;
	}
      (i % (READ_SIZE + 1) == 0) ? line = remalloc(line, i) : 0;
    }
  line[i] = '\0';
  return (line);
}
