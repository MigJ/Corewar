/*
** writes.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Wed Mar 29 13:59:47 2017 Kévin Laspougeas
** Last update Wed Mar 29 14:10:39 2017 Kévin Laspougeas
*/

#include "asm.h"

void	write_inst(t_inst *inst, const int fd_out)
{
  int	x;

  x = 0;
  write(fd_out, inst->name, 1);
  if (c_byte != 0)
    write(fd_out, &c_byte, 1);
  while (inst->args[x] != NULL)
    write(fd_out, &inst->args[x][1], (size_t)my_getnbr(inst->args[x++][0]));
}

void	write_it_all(t_list *list, const int fd_out)
{
  t_inst	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      write_inst(tmp, fd_out);
      tmp = tmp->next;
    }
  free(tmp);
}
