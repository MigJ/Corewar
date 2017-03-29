/*
** free.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Tue Mar 28 17:37:12 2017 Kévin Laspougeas
** Last update Wed Mar 29 21:48:00 2017 Kévin Laspougeas
*/

#include "asm.h"

void	free_list(t_list *list)
{
  t_inst	*tmp;

  while (list->first != NULL)
    {
      tmp = list->first;
      free(tmp->name);
      free(tmp->args);
      list->first = tmp->next;
      free(tmp);
    }
}
