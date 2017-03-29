/*
** fill_inst.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Wed Mar 29 18:16:25 2017 Kévin Laspougeas
** Last update Thu Mar 30 01:15:10 2017 Kévin Laspougeas
*/

#include "asm.h"

int	fill_instruction(char *line, t_inst *toadd, t_list *list)
{
  toadd->size = ret_params_size(line);
  toadd->c_byte = convert_bin_to_dec(ret_oct_from_line(line));
  toadd->args = ret_content(line);
  add_to_list(list, toadd);
  return (1);
}
