/*
** writes.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Wed Mar 29 13:59:47 2017 Kévin Laspougeas
** Last update Fri Mar 31 17:18:24 2017 Kévin Laspougeas
*/

#include "asm.h"

void	write_inst(t_inst *inst, const int fd_out)
{
  write(fd_out, inst->name, 1);
  if (inst->name[0] != 1 && inst->name[0] != 9 && inst->name[0] != 12 &&
      inst->name[0] != 15)
    write(fd_out, &inst->c_byte, 1);
  write(fd_out, inst->args, inst->size - (inst->name[0] == 1 ||
	inst->name[0] == 9 || inst->name[0] == 12 || inst->name[0] == 15 ?
					  1 : 2));
}

void	write_size_head(const int fd_out, t_list *list)
{
  lseek(fd_out, PROG_NAME_LENGTH + 8, SEEK_SET);
  list->size = ((list->size >> 24) & 0xff) | ((list->size << 8) & 0xff0000) |
    ((list->size >> 8) & 0xff00) | ((list->size << 24) & 0xff000000);
  write(fd_out, &list->size, sizeof(int));
}

void	write_it_all(t_list *list, const int fd_out)
{
  t_inst	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      if (tmp->name[0] <= 16)
	write_inst(tmp, fd_out);
      tmp = tmp->next;
    }
  write_size_head(fd_out, list);
}
