/*
** my_strcpy.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 08:54:28 2016 Kévin Laspougeas
** Last update Thu Nov 24 14:08:39 2016 Kévin Laspougeas
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (src)
    {
      while (src[i])
	dest[i] = src[i++];
      dest[i] = '\0';
    }
  return (dest);
}
