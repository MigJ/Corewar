/*
** init_content.c for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sun Apr  2 17:15:51 2017 Joubert Miguel
** Last update Sun Apr  2 17:28:20 2017 Joubert Miguel
*/

#include "asm.h"

t_content		init_content(t_content cont, char *line,
				     t_inst *inst)
{
  if ((inst->lbl = malloc(sizeof(char*) * 3)) == NULL)
    return (cont);
  inst->lbl[0] = NULL;
  inst->lbl[1] = NULL;
  cont.sbs = my_memset(4);
  cont.new_args = my_memset(ret_params_size(line) + T_LAB);
  if ((cont.argus = malloc(sizeof(char *) * 10)) == NULL)
    return (cont);
  cont.argus = my_str_sep(line, SEPARATOR_CHAR);
  cont.j = cont.i = cont.l = 0;
  cont.sbs = ret_size_sbs(line, inst->name);
  inst->size = get_size_sbs(cont.sbs);
  return (cont);
}
