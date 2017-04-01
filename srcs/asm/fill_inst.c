/*
** fill_inst.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Wed Mar 29 18:16:25 2017 Kévin Laspougeas
** Last update Sat Apr  1 14:26:53 2017 Joubert Miguel
*/

#include "asm.h"

char	*is_there_a_label(t_inst *inst)
{
  if (inst->lbl != NULL)
    return (inst->lbl);
  return (NULL);
}

void	place_label(t_inst *inst, int offset, t_list *list, int place)
{
  int	i;
  int	j;
  char	*add;
  
  i = -1;
  j = 0;
  add = my_memset(2);
  while (i < (place - 1))
    i++;
  add = chartab_to_char(add, offset, &j);
  inst->args[i] = add[0];
  inst->args[i + 1] = add[1];
  free(add);
}

void	run_label(t_inst *tmp, char *to_find, t_list *list, int size)
{
  int		diff;
  t_inst	*tmp2;

  diff = 0;
  tmp2 = list->first;
  while (tmp2 != NULL && my_strstr(to_find, tmp2->name) == NULL)
    {
      diff += tmp2->size;
      tmp2 = tmp2->next;
    }
  if (tmp2 != NULL && is_in_twice(to_find, list) == 0)
    place_label(tmp, diff - size, list, get_place(tmp));
  else
    exit_stage_2(to_find, list, WRG_LABEL);
}

void	fill_labels(t_list *list)
{
  t_inst	*tmp;
  char		*to_find;
  int		size;

  tmp = list->first;
  size = 0;
  if (tmp != NULL)
    {
      while (tmp != NULL)
	{
	  if ((to_find = is_there_a_label(tmp)) != NULL)
	    {
	      run_label(tmp, to_find, list, size);
	      free(to_find);
	    }
	  size += tmp->size;
	  tmp = tmp->next;
	}
    }
}

int	fill_instruction(char *line, t_inst *toadd, t_list *list)
{
  toadd->c_byte = convert_bin_to_dec(ret_oct_from_line(line));
  toadd->args = ret_content(line, toadd);
  add_to_list(list, toadd);
  return (1);
}
