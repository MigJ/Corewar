/*
** get_size.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Tue Mar 28 03:05:46 2017 Kévin Laspougeas
** Last update Tue Mar 28 04:14:08 2017 Kévin Laspougeas
*/

#include "asm.h"

int	is_dir(char *str);
int	is_ind(char *str);
int	is_reg(char *str);

void	get_size(char *str, t_inst *inst, t_list *list)
{
  char	**args;
  int	x;

  x = 0;
  args = my_strsep(str, ',');
  while (args[x] != NULL)
    {
      list->size += is_ind(args[x]) == 1 && inst->name[0] != 10 &&
	inst->name[0] != 14 && inst->name[0] != 15 ? 4 : is_reg(args[x]) ? 1 :
	is_dir(args[x]) ? 2 : is_ind(args[x]) == 1 ? 2 : 44;
      list->size += inst->name[0] != 1 && inst->name[0] != 9 &&
	inst->name[0] != 12 && inst->name[0] != 15 ? 2 : 1;
      x++;
    }
}
