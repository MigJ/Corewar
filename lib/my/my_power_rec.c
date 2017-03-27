/*
** mu_power_rec.c for CPool_Day05 in /home/laspou_k/delivery/CPD5
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Fri Oct  7 10:39:08 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:03:24 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_power_rec(int nb, int p)
{
  if (p < 0)
    return (0);
  else if (p == 0)
    return (1);
  return (nb * my_power_rec(nb, (p - 1)));
}
