/*
** free.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Tue Mar 28 17:37:12 2017 Kévin Laspougeas
** Last update Sat Apr  1 15:21:21 2017 Kévin Laspougeas
*/

#include "asm.h"

void	free_list(t_list *list)
{
  t_inst	*tmp;

  while (list->first != NULL) {
    tmp = list->first;
    list->first = list->first->next;
    free(tmp);
  }
}
