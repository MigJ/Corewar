/*
** my_memset_array.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Sat Apr  1 18:10:34 2017 Kévin Laspougeas
** Last update Sat Apr  1 18:14:50 2017 Kévin Laspougeas
*/

#include "asm.h"

void	*my_memset_array(void *arr, int c, size_t n)
{
  int	x;

  x = 0;
  while (x < n)
    arr[x++] = c;
  return (arr);
}
