/*
** my_put_nbr.c for CPool_Day03 in /home/laspou_k/delivery/CPool_Day03
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Wed Oct  5 15:03:56 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:04:05 2016 Kévin Laspougeas
*/

#include "my.h"

int	mod_find(int n)
{
  int	stor;
  int	mod;

  mod = 1;
  stor = n;
  while (stor > 9)
    {
      mod = mod * 10;
      stor = stor / 10;
    }
  return (mod);
}

int	my_put_nbr(int nb)
{
  int	mod;
  int	tmp;

  if (nb < 0)
    {
      my_putchar('-');
      tmp = nb * -1;
      nb = nb * -1;
    }
  else
    tmp = nb;
  mod = mod_find(tmp);
  while (mod >= 1)
    {
      tmp = tmp / mod;
      my_putchar(tmp + '0');
      tmp = nb % mod;
      mod = mod / 10;
    }
}
