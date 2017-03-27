/*
** disp_stdarg.c for printfbootstrap in ~/delivery/PSU_2016_my_printf_bootstrap
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Mon Nov  7 14:14:05 2016 Kévin Laspougeas
** Last update Mon Nov  7 14:42:01 2016 Kévin Laspougeas
*/

#include "my.h"
#include <stdarg.h>

int	disp_stdarg(char *s, ...)
{
  va_list	va_args;

  va_start(va_args, s);
  while (*s)
    {
      if (*s == 'c')
	my_putchar(va_arg(va_args, int));
      else if (*s == 's')
	my_putstr(va_arg(va_args, char*));
      else if (*s == 'i')
	my_put_nbr(va_arg(va_args, int));
      if (*s == 'c' || *s == 's' || *s == 'i')
	my_putchar('\n');
      s++;
    }
  va_end(va_args);
  return (1);
}
