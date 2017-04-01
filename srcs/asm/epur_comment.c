/*
** epur_comment.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Sat Apr  1 00:42:11 2017 Kévin Laspougeas
** Last update Sat Apr  1 01:21:19 2017 Kévin Laspougeas
*/

#include "asm.h"

char	*epur_com(char *args)
{
  int	i;

  i = 0;
  while (args[i] != '\0') {
    if (args[i] == COMMENT_CHAR) {
	args[i] = '\0';
	break;
    }
    i++;
  }
  return (args);
}
