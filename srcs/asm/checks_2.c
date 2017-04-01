/*
** check_args2.c for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Mar 27 23:54:16 2017 Kévin Laspougeas
** Last update Sat Apr  1 15:35:35 2017 Kévin Laspougeas
*/

#include "asm.h"

int	is_reg(char *str);
int	is_dir(char *str);
int	is_ind(char *str);
int	is_label(char *str);

int	check_zjmp(char *str, t_list *list)
{
  t_inst	*zjmp;
  char		c;

  c = 9;
  zjmp = malloc(sizeof(t_inst));
  zjmp->name = my_strn_dup(&c, 1);
  if (str == NULL || (is_dir(str) != 1 && is_label(str) != 1))
    return (0);
  return (fill_instruction(str, zjmp, list));
}

int	check_ldi(char *str, t_list *list, char nme)
{
  int		x;
  char		**args;
  t_inst	*ldi;

  x = 0;
  ldi = malloc(sizeof(t_inst));
  ldi->name = my_strn_dup(&nme, 1);
  if (str == NULL)
    return (0);
  args = my_str_sep(str, SEPARATOR_CHAR);
  while (args[x] != NULL) {
    if (x == 0 && !is_dir(args[x]) && !is_ind(args[x]) && !is_label(args[x]))
      return (0);
    else if (x == 1 && !is_dir(args[x]) && !is_ind(args[x]) &&
	     !is_label(args[x]))
      return (0);
    else if (x == 2 && !is_reg(args[x]))
      return (0);
    x++;
  }
  if (x != 3)
    return (0);
  return (fill_instruction(str, ldi, list));
}

int	check_sti(char *str, t_list *list, char nme)
{
  int		x;
  char		**args;
  t_inst	*sti;

  x = 0;
  sti = malloc(sizeof(*sti));
  sti->name = my_strn_dup(&nme, 1);
  if (str == NULL)
    return (0);
  args = my_str_sep(str, SEPARATOR_CHAR);
  while (args[x] != NULL) {
    if (x == 0 && !is_reg(args[x]))
      return (0);
    else if (x == 1 && !is_reg(args[x]) && !is_dir(args[x]) &&
	     !is_label(args[x]) && !is_ind(args[x]))
      return (0);
    else if (x == 2 && !is_reg(args[x]) && !is_dir(args[x]) &&
	     !is_label(args[x]) && !is_ind(args[x]))
      return (0);
    x++;
  }
  if (x != 3)
    return (0);
  return (fill_instruction(str, sti, list));
}

int	check_fork(char *str, t_list *list, char nme)
{
  t_inst	*fork;
  char		**args;

  fork = malloc(sizeof(t_inst));
  fork->name = my_strn_dup(&nme, 1);
  args = my_str_sep(str, SEPARATOR_CHAR);
  if (args[0] == NULL || (is_dir(args[0]) != 1 && args[1] != NULL))
    return (0);
  return (fill_instruction(str, fork, list));
}

int	check_aff(char *str, t_list *list)
{
  t_inst	*aff;
  char		c;
  char		**args;

  c = 16;
  aff = malloc(sizeof(t_inst));
  aff->name = my_strn_dup(&c, 1);
  args = my_str_sep(str, SEPARATOR_CHAR);
  if (args[0] == NULL || (is_reg(args[0]) != 1 && args[1] != NULL))
    return (0);
  return (fill_instruction(str, aff, list));
}
