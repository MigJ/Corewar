/*
** fill_inst.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Wed Mar 29 18:16:25 2017 Kévin Laspougeas
** Last update Fri Mar 31 01:14:00 2017 Kévin Laspougeas
*/

#include "asm.h"

char	*is_there_a_label(t_inst *inst)
{
  int	i;
  int	j;
  char	*ret;

  i = j = 0;
  ret = my_memset(T_LAB + 1);
  while (i < inst->size && is_in_label_char(inst->args[i], LABEL_CHARS) != 1)
    i++;
  while (is_in_label_char(inst->args[i], LABEL_CHARS) == 1)
    ret[j++] = inst->args[i++];
  ret[j] = '\0';
  return (ret[0] == '\0' ? NULL : ret);
}

void	place_label(t_inst *inst, int offset, t_list *list)
{
  int	i;
  char	*add;
  
  i = -1;
  add = my_memset(inst->size);
  while (++i < inst->size && inst->args[i] <= 16)
    add[i] = inst->args[i];
  if (inst->args[i] > 16)
    {
      i--;
      add = int_to_char(add, offset, &i);
      i--;
      while (++i < inst->size)
	add[i] = inst->args[i];
      i = -1;
      while (++i < inst->size)
	inst->args[i] = add[i];
      free(add);
    }
  else
    exit_stage_2(inst->name, list, WRG_LABEL);
}

void	run_label(t_inst *tmp, t_inst *tmp2, char *to_find, t_list *list)
{
  int	diff;

  diff = 0;
  while (tmp2 != NULL && my_strcmp(to_find, tmp2->name) != 0)
    {
      diff += tmp2->size;
      tmp2 = tmp2->next;
    }
  if (tmp != NULL)
    place_label(tmp, diff - tmp->size, list);
  else
    exit_stage_2(to_find, list, WRG_LABEL);
}

void	fill_labels(t_list *list)
{
  t_inst	*tmp;
  t_inst	*tmp2;
  char		*to_find;

  tmp = list->first;
  if (tmp != NULL)
    {
      while (tmp != NULL)
	{
	  if ((to_find = is_there_a_label(tmp)) != NULL)
	    {
	      tmp2 = list->first;
	      run_label(tmp, tmp2, to_find, list);
	      free(to_find);
	    }
	  tmp = tmp->next;
	}
    }
}

int	fill_instruction(char *line, t_inst *toadd, t_list *list)
{
  toadd->size = ret_params_size(line);
  toadd->c_byte = convert_bin_to_dec(ret_oct_from_line(line));
  toadd->args = ret_content(line);
  add_to_list(list, toadd);
  return (1);
}
