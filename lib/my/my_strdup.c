/*
** my_strdup.c for CPool_Day08 in /home/laspou_k/delivery/CPool_Day08/task01
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Thu Oct 13 09:21:48 2016 Kévin Laspougeas
** Last update Tue Oct 18 09:04:50 2016 Kévin Laspougeas
*/

#include "my.h"

char	*my_strdup(char *src)
{
  char	*todup;

  todup = xmalloc(sizeof(char) * my_strlen(src) + 1);
  my_strcpy(todup, src);
  return (todup);
}
