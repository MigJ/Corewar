/*
** my_putnbr_blong.c for putnbr in ~/delivery/PSU/PSU_2016_my_printf
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Sat Nov 19 17:57:03 2016 Kévin Laspougeas
** Last update Sat Nov 19 18:11:35 2016 Kévin Laspougeas
*/

#include "my.h"

void	my_putnbr_blong(long nb, char *base)
{
  long	tmp;
  long	mod;

  (nb < 0) ? (my_putchar('-')) : (nb = nb);
  nb = (nb < 0) ? (nb * -1) : (nb);
  tmp = nb;
  mod = 1;
  while (tmp >= my_strlen(base))
    {
      mod = mod * my_strlen(base);
      tmp = tmp / my_strlen(base);
    }
  tmp = nb;
  while (mod >= 1)
    {
      tmp = tmp / mod;
      my_putchar(base[tmp]);
      tmp = nb % mod;
      mod = mod / my_strlen(base);
    }
}
