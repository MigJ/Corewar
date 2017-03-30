/*
** writes.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Wed Mar 29 13:59:47 2017 Kévin Laspougeas
** Last update Thu Mar 30 16:48:56 2017 Kévin Laspougeas
*/

#include "asm.h"

void	write_inst(t_inst *inst, const int fd_out)
{
  write(fd_out, inst->name, 1);
  if (inst->c_byte != 0)
    write(fd_out, &inst->c_byte, 1);
  write(fd_out, inst->args, inst->size);
}

void	write_it_all(t_list *list, const int fd_out)
{
  t_inst	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      if (tmp->name[0] < 16)
	write_inst(tmp, fd_out);
      tmp = tmp->next;
    }
}
