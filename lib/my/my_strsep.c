/*
** my_strsep.c for mylib in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Tue Mar 28 03:08:57 2017 Kévin Laspougeas
** Last update Tue Mar 28 03:18:28 2017 Kévin Laspougeas
*/

#include "my.h"

char	**my_strsep(const char *str, const char sep)
{
  char	**ret;
  int	x;
  int	y;
  int	i;

  i = x = 0;
  if ((ret = malloc(sizeof(char*) * my_strlen(str))) == NULL || str == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      y = 0;
      if ((ret[x] = malloc(sizeof(char) * my_strlen(str))) == NULL)
	return (NULL);
      while (str[++i] != '\0' && str[i] != sep)
	ret[x][y++] = str[i];
      i++;
      x++;
    }
  ret[x] = NULL;
  return (ret);
}
