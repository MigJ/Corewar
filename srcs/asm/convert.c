/*
** convert10to2.c for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Mar 28 01:57:24 2017 Joubert Miguel
** Last update Sun Apr  2 17:08:41 2017 Joubert Miguel
*/

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"

unsigned char		convert_bin_to_dec(int bin)
{
  int			sum;
  int			rem;
  int			power;

  sum = rem = power = 0;
  while (bin > 0)
    {
      rem = bin % 10;
      bin = bin / 10;
      sum = sum + rem * my_power_rec(2, power);
      power++;
    }
  return (sum);
}

char		*convert10to2(unsigned char nb_char)
{
  char		base_digits[16] =
    {'0', '1', '2', '3', '4', '5', '6', '7',
     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  char		*converted;
  int		converted_number[64];
  int		base;
  int		index;
  int		nb;
  int		i;

  i = index = 0;
  nb = nb_char;
  base = 2;
  converted = my_memset(30);
  while (nb != 0) {
    converted_number[index] = nb % base;
    nb = nb / base;
    ++index;
  }
  --index;
  while (index>=0) {
    converted[i] = base_digits[converted_number[index]];
    i++, index--;
  }
  return (converted);
}
