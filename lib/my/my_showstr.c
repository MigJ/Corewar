/*
** my_showstr.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 14:14:34 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:04:34 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < ' ' || str[i] == 127)
	{
	  my_putchar('\\');
	  if (str[i] < 16)
	    my_putchar('0');
	  my_putnbr_base(str[i], "0123456789abcedf");
	  i++;
	}
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
