/*
** my_strcat.c for CPool_Day07 in /home/laspou_k/delivery/CPool_Day07
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 14:19:34 2016 Kévin Laspougeas
** Last update Thu Nov 24 14:29:43 2016 Kévin Laspougeas
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(dest);
  while (src[i])
    dest[j++] = src[i++];
  dest[j] = '\0';
  return (dest);
}
