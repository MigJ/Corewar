/*
** my_putnbr_base.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 11:22:17 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:03:55 2016 Kévin Laspougeas
*/

#include "my.h"

int	find_mod_base(int n, int base)
{
  int	stor;
  int	mod;

  mod = 1;
  stor = n;
  while (stor >= base)
    {
      mod = mod * base;
      stor = stor / base;
    }
  return (mod);
}

int	my_putnbr_base(int nbr, char *base)
{
  int	mod;
  int	tmp;

  if (nbr < 0)
    {
      my_putchar('-');
      tmp = nbr * -1;
      nbr = nbr * -1;
    }
  else
    tmp = nbr;
  mod = find_mod_base(tmp, my_strlen(base));
  while (mod >= 1)
    {
      tmp = tmp / mod;
      my_putchar(base[tmp]);
      tmp = nbr % mod;
      mod = mod / my_strlen(base);
    }
}
