/*
** my_showstr.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 14:14:34 2016 Kévin Laspougeas
** Last update Mon Nov  7 17:52:43 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_showstr_oct(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      while ((str[i] < ' ' || str[i] > 126) && str[i])
	{
	  my_putchar('\\');
	  if (str[i] < 64 && str[i] > 7)
	    my_putchar('0');
	  else if (str[i] <= 7)
	    my_putstr("00");
	  my_putnbr_base(str[i], "01234567");
	  i++;
	}
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
