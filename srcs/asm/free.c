/*
** free.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Tue Mar 28 17:37:12 2017 Kévin Laspougeas
** Last update Tue Mar 28 17:40:20 2017 Kévin Laspougeas
*/

#include "asm.h"

void	free_list(t_list *list)
{
  t_inst	*tmp;
  int		x;

  while (list->first != NULL)
    {
      tmp = list->first;
      x = 0;
      free(tmp->name);
      while (tmp->args[x] != NULL)
	free(tmp->args[x++]);
      list->first = tmp->next;
      free(tmp);
    }
}
