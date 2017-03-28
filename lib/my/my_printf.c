/*
** my_printf.c for my_printf in /home/laspou_k/delivery/PSU_2016_my_printf
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Mon Nov  7 15:15:23 2016 Kévin Laspougeas
** Last update Tue Mar 28 01:35:16 2017 Kévin Laspougeas
*/

#include <stdarg.h>
#include <stdint.h>
#include "my.h"

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

void	putnbrform(int nb, char *s)
{
  int	x;
  int	m;
  int	i;

  m = nb;
  i = 0;
  while (m > 0)
    {
      m = m / 10;
      i++;
    }
  x = (*s - '0') - i;
  *s++;
  while (x-- > 0 && (*s == 'd' || *s == 'i' || *s == 'x' || *s == 'o' ||
		     *s == 'X'))
    my_putchar(' ');
  (*s == 'd' || *s == 'i') ? (my_put_nbr(nb)) : (*s == 'o') ?
    (my_putnbr_base(nb, "01234567")) : (*s == 'x') ?
    (my_putnbr_base(nb, "0123456789abcdef")) : (*s == 'X') ?
    (my_putnbr_base(nb, "0123456789ABCDEF")) : (*s);
}

void	check_format(char *s, va_list varg)
{
  (*s == 'o') ? (my_putnbr_base(va_arg(varg, int), "01234567")) :
    (*s >= '0' && *s <= '9') ? (putnbrform(va_arg(varg, int), s++)) :
    (*s == '%') ? (my_putchar('%')) :
    (*s == 'X') ? (my_putnbr_base(va_arg(varg, int),
				  "0123456789ABCDEF")) : (*s);
}

int	my_printf(char *s, ...)
{
  va_list	varg;

  va_start(varg, s);
  while (*s)
    {
      if (*s == '%')
	{
	  *s++;
	  (*s == 'd' || *s == 'i') ? (my_put_nbr(va_arg(varg, int))) :
	    (*s == 'c') ? (my_putchar(va_arg(varg, int))) :
	    (*s == 's') ? (my_putstr(va_arg(varg, char*))) :
	    (*s == 'S') ? (my_showstr_oct(va_arg(varg, char*))) :
	    (*s == 'p') ? (my_show_ptr((uintptr_t)va_arg(varg, void*))) :
	    (*s == 'b') ? (my_putnbr_base(va_arg(varg, int), "01")) :
	    (*s == 'x') ? (my_putnbr_base(va_arg(varg, int),
					  "0123456789abcdef")) :
	    (check_format(s, varg));
	  s = (*s >= '0' && *s <= '9' && *s + 1 != ' ') ? (&s[2]) : (&s[1]);
	}
      else
	my_putchar(*s++);
    }
  va_end(varg);
  return (1);
}
