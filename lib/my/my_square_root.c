/*
** my_square_root.c for CPool_Day05 in /home/laspou_k/delivery/CPD5
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Fri Oct  7 11:23:04 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:05:16 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_square_root(int nb)
{
  int	beg;
  int	mid;
  int	end;
  int	res;

  beg = 1;
  end = nb;
  if (nb == 0 || nb == 1)
    return (nb);
  else if (nb < 0)
    return (0);
  while (beg <= end)
    {
      mid = (beg + end) / 2;
      if (mid == (nb / mid))
	return (mid);
      else if (mid < (nb / mid))
	{
	  beg = mid + 1;
	  res = mid;
	}
      else
	end = mid - 1;
    }
  return (res);
}
