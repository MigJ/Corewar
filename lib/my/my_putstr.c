/*
** my_putstr.c for CPool_Day07 in /home/laspou_k/delivery/CPool_Day07
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 14:25:56 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:03:41 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}
