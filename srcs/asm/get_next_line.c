/*
** get_next_line.c for gnl in /home/laspou_k/delivery/CPE/CPE_2016_getnextline
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Jan  3 21:43:06 2017 Kévin Laspougeas
** Last update Sun Jan 22 18:50:26 2017 Kévin Laspougeas
*/

#include "get_next_line.h"

size_t	my_strlen(const char *str)
{
  size_t	i;

  if (str)
    {
      i = 0;
      while (str[i] != '\0')
	i++;
      return (i);
    }
  return (0);
}

char	*my_strncadup(char *ret, const char *buff, int n)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(ret) + my_strlen(buff) + 1))) ==
      NULL)
    return (NULL);
  if (ret)
    {
      i = -1;
      while (ret[++i] != '\0')
	new[i] = ret[i];
    }
  while (j < n)
    new[i++] = buff[j++];
  new[i] = '\0';
  return (new);
}

int	find_end(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n' && str[i] != '\0')
    i++;
  return (str[i] == '\n' ? i : -1);
}

char	*get_next_line(const int fd)
{
  static char	*buff;
  static char	*to_ret;
  char		*ret;
  int		n;

  ret = NULL;
  if (buff == NULL)
    {
      if ((buff = malloc(sizeof(char) * READ_SIZE + 1)) == NULL ||
	  (n = read(fd, buff, READ_SIZE)) <= 0)
	return (NULL);
      return (get_next_line(fd));
    }
  else if (buff != NULL && (n = find_end(buff)) >= -1)
    {
      to_ret = my_strncadup(to_ret, buff, n == -1 ? (int)my_strlen(buff) : n);
      if (n != -1)
	{
	  ret = my_strncadup(ret, to_ret, my_strlen(to_ret));
	  to_ret = NULL;
	}
      buff = n == -1 ? NULL : &buff[n + 1];
      return (n == -1 ? get_next_line(fd) : ret);
    }
  return (NULL);
}
