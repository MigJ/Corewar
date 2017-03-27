/*
** my_putchar.c for CPoo_Day07 in /home/laspou_k/delivery/CPool_Day07
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 14:25:08 2016 Kévin Laspougeas
** Last update Tue Oct 18 09:00:32 2016 Kévin Laspougeas
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
