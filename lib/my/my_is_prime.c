/*
** my_is_prime.c for CPool_Day05 in /home/laspou_k/delivery/CPD5
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Fri Oct  7 11:44:36 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:03:12 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_is_prime(int nb)
{
  int	dec;

  dec = nb - 1;
  if (nb <= 1)
    return (0);
  else if (nb == 2)
    return (1);
  while (dec > 1)
    {
      if ((nb % dec) == 0)
	return (0);
      dec--;
    }
  return (1);
}
