/*
** get_size.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Tue Mar 28 03:05:46 2017 Kévin Laspougeas
** Last update Thu Mar 30 20:10:21 2017 Kévin Laspougeas
*/

#include "asm.h"

int	is_in_label_char(char c, char *chars)
{
  int	i;

  i = 0;
  while (chars[i] != '\0')
    {
      if (c == chars[i])
	return (1);
      i++;
    }
  return (0);
}
