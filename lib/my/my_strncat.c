/*
** my_strncat.c for CPool_Day07 in /home/laspou_k/delivery/CPool_Day07
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 14:22:38 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:07:10 2016 Kévin Laspougeas
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(dest);
  while (i < nb && src[i] != '\0')
    dest[j++] = src[i++];
  dest[j] = '\0';
}
