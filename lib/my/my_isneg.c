/*
** my_isneg.c for CPool_Day03 in /home/laspou_k/delivery/CPool_Day03
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Wed Oct  5 10:41:42 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:02:46 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n >= 0)
    my_putchar('P');
  else
    my_putchar('N');
}
