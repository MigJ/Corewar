/*
** xmalloc.c for xmalloc in /home/laspou_k/delivery/CPool_Day08
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Thu Oct 13 09:30:52 2016 Kévin Laspougeas
** Last update Tue Oct 18 09:08:15 2016 Kévin Laspougeas
*/

#include <stdlib.h>

void	*xmalloc(size_t n)
{
  void	*ptr;

  if ((ptr = malloc(n)) == NULL)
    return (NULL);
  return (ptr);
}
