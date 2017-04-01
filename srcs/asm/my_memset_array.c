/*
** my_memset_array.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Sat Apr  1 18:10:34 2017 Kévin Laspougeas
** Last update Sat Apr  1 18:12:40 2017 Kévin Laspougeas
*/

#include "asm.h"

void	*my_memset_array(void *arr, int c, size_t n, size_t m)
{
  int	x;
  int	y;

  x = 0;
  while (x < n) {
    y = 0;
    while (y < m) {
      arr[x][y++] = 0;
    }
    x++;
  }
  return (arr);
}
