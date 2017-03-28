/*
** my_show_ptr.c for showptr in /home/laspou_k/delivery/PSU_2016_my_printf
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Nov  7 15:37:23 2016 Kévin Laspougeas
** Last update Tue Mar 28 01:35:28 2017 Kévin Laspougeas
*/

#include <stdint.h>
#include "my.h"

void	my_show_ptr(uintptr_t ptr)
{
  my_putstr("0x");
  my_putnbr_blong((long)ptr, "0123456789abcdef");
}
