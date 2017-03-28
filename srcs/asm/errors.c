/*
** errors.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Tue Mar 28 01:26:09 2017 Kévin Laspougeas
** Last update Tue Mar 28 17:50:14 2017 Kévin Laspougeas
*/

#include "asm.h"

void	exit_error(char *str, int line, int cas)
{
  write(2, str, my_strlen(str));
  write(2, cas == WRG_MNEMO ? " :: Unknow instruction line " :
	cas == WRG_PAR ? " :: Invalid parameter line " : "?",
	cas == WRG_MNEMO ? 28 : cas == WRG_PAR ? 27 : 1);
  my_put_nbr(line);
  write(2, "\n", 1);
  exit(84);
}

int	exit_stage_2(char *name, t_list *list, int cas)
{
  write(2, name, my_strlen(name));
  write(2, cas == WRG_LABEL ? " :: Label not found !" : "?",
	cas == WRG_LABEL ? 21, 1);
  write(2, "\n", 1);
  free_list(list);
  exit(84);
  return (0);
}
