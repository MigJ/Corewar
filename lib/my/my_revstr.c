/*
** my_revstr.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 09:11:10 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:04:17 2016 Kévin Laspougeas
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  char	*tmp;

  tmp = xmalloc(sizeof(char) * my_strlen(str));
  i = 0;
  j = my_strlen(str) - 1;
  while (j >= 0)
    tmp[j--] = str[i++];
  return (tmp);
}
