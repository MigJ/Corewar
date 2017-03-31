/*
** check_parse.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Fri Mar 31 02:02:37 2017 Kévin Laspougeas
** Last update Fri Mar 31 22:10:09 2017 Kévin Laspougeas
*/

#include "asm.h"

int	get_place(t_inst *inst)
{
  int	i;

  while (inst->lbl[i] != SEPARATOR_CHAR)
    i++;
  return ((int)(inst->lbl[i + 1] - '0'));
}

int	is_rg(char *args, int p)
{
  char	**argus;

  argus = my_str_sep(args, SEPARATOR_CHAR);
  return (is_reg(argus[p - 1]));
}

int	is_dr(char *args, int p)
{
  char	**argus;

  argus = my_str_sep(args, SEPARATOR_CHAR);
  return (is_dir(argus[p - 1]));
}

char	*set_three_params(char *args, char *nme)
{
  char	*ret;

  ret = my_memset(4);
  ret[0] = nme[0] == 4 || nme[0] == 5 ? '1' : nme[0] == 6 || nme[0] == 7 ||
    nme[0] == 8 ?
    (is_rg(args, 1) ? '1' : is_dr(args, 1) ? '4' : '2') : nme[0] == 10 ||
    nme[0] == 14 ? '2' : '1';
  ret[1] = nme[0] == 4 || nme[0] == 5 ? '1' : nme[0] == 6 || nme[0] == 7 ||
    nme[0] == 8 ?
    (is_rg(args, 2) ? '1' : is_dr(args, 2) ? '4' : '2') : nme[0] == 10 ||
    nme[0] == 14 ? '2' : nme[0] == 11 ? '2' : '1';
  ret[2] = nme[0] == 4 || nme[0] == 5 ? '1' : nme[0] == 6 || nme[0] == 7 ||
    nme[0] == 8 ? '1' : nme[0] == 10 || nme[0] == 14 ? '1' : nme[0] == 11 ?
    (is_dr(args, 3) ? '2' : is_rg(args, 3) ? '1' : '2') : '1';
  ret[3] = '\0';
  return (ret);
}

char	*ret_size_sbs(char *args, char *nme)
{
  char	*ret;

  ret = my_memset(4);
  if (nme[0] > 16)
    return (nme);
  if (nme[0] == 1 || nme[0] == 9 || nme[0] == 12 || nme[0] == 15 ||
      nme[0] == 16)
    return (nme[0] == 1 ? "4" : nme[0] == 9 || nme[0] == 12 ? "2" :
	    nme[0] == 15 ? "2" : "1");
  else if (nme[0] == 2 || nme[0] == 3 || nme[0] == 13) {
    ret[0] = nme[0] == 2 || nme[0] == 13 ?
      (is_dr(args, 1) ? '2' : is_rg(args, 1) ? '1' : '2') : '1';
    ret[1] = nme[0] == 3 ? (is_rg(args, 2) ? '1' : '2') : '1';
    ret[2] = '\0';
  }
  else
    ret = set_three_params(args, nme);
  return (ret);
}
