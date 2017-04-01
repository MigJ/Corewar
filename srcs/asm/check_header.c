/*
** check_header.c for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Apr  1 12:50:49 2017 Joubert Miguel
** Last update Sat Apr  1 15:28:45 2017 Joubert Miguel
*/

#include "asm.h"

int		check_header_quotes(char *str)
{
  int		i;
  int		count;

  if (!str)
    return (-1);
  i = -1;
  count = 0;
  while (str[++i]) {
    if (str[i] == '"')
      count++;
  }
  return (count);
}
