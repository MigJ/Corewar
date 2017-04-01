/*
** check_header.c for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Apr  1 15:39:28 2017 Joubert Miguel
** Last update Sat Apr  1 15:41:40 2017 Joubert Miguel
*/

#include "asm.h"

int		check_header_quotes(char *str)
{
  int		i;
  int		count;

  if (!str)
    return (-1);
  count = 0;
  i = -1;
  while (str[++i]) {
    if (str[i] == '"')
      count++;
  }
  return (count);
}
