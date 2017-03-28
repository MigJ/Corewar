/*
** sum_stdarg.c for printf_bootstrap in ~/delivery/PSU_2016_my_printf_bootstrap
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Nov  7 13:42:59 2016 Kévin Laspougeas
** Last update Tue Mar 28 01:35:38 2017 Kévin Laspougeas
*/

#include <stdarg.h>
#include "my.h"

int	sum_stdarg(int i, int nb, ...)
{
  va_list	args;
  int		res;
  int		x;

  res = 0;
  x = nb;
  va_start(args, nb);
  if (i == 0)
    {
      while (--x >= 0)
	res = res + va_arg(args, int);
    }
  else if (i == 1)
    {
      while (--x >= 0)
	res = res + my_strlen(va_arg(args, char*));
    }
  va_end(args);
  return (res);
}
