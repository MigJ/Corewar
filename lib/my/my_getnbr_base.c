/*
** my_getnbr_base.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 13:18:58 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:02:23 2016 Kévin Laspougeas
*/

#include "my.h"

int	place_base(char n, char *base)
{
  int	i;

  i = 0;
  if (n == '\0')
    return (-1);
  while (base[i])
    {
      if (n == base[i])
	return (i);
      i++;
    }
  return (-1);
}

int	check_str_base(char *str, char *base)
{
  int	i;
  int	sign;

  sign = 1;
    i = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	sign = sign * -1;
      i++;
    }
  while (str[i])
    {
      if (place_base(str[i], base) < 0)
	return (0);
      i++;
    }
  return (sign);
}

int	my_getnbr_base(char *str, char *base)
{
  int	tmp;
  int	sign;
  int	i;
  int	j;

  i = 0;
  j = 0;
  sign = 1;
  if (str)
    {
      tmp = 0;
      if ((sign = check_str_base(str, base)) != 1 &&
	  (sign = check_str_base(str, base)) != -1)
	return (0);
      i = my_strlen(str) - 1;
      while (i >= 0 && place_base(str[i], base) >= 0)
	{
	  tmp = tmp + place_base(str[i--], base) *
	    my_power_rec(my_strlen(base), j++);
	}
      return (tmp * sign);
    }
  return (0);
}
