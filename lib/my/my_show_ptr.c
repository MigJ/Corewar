/*
** my_show_ptr.c for showptr in /home/laspou_k/delivery/PSU_2016_my_printf
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Nov  7 15:37:23 2016 Kévin Laspougeas
** Last update Sat Nov 19 18:06:12 2016 Kévin Laspougeas
*/

#include "my.h"
#include <stdint.h>

void	my_show_ptr(uintptr_t ptr)
{
  my_putstr("0x");
  my_putnbr_blong((long)ptr, "0123456789abcdef");
}
