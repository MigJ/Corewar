/*
** check_args2.c for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Mar 27 23:54:16 2017 Kévin Laspougeas
** Last update Sun Apr  2 17:30:59 2017 Joubert Miguel
*/

#include "asm.h"

int	is_reg(char *str);
int	is_dir(char *str);
int	is_ind(char *str);
int	is_label(char *str);

int	check_zjmp(char *str, t_list *list)
{
  t_inst	*zjmp;
  char		**args;
  char		c;

  c = 9;
  if ((zjmp = malloc(sizeof(t_inst))) == NULL)
    return (84);
  zjmp->name = my_strndup(&c, 1);
  args = my_str_sep(str, SEPARATOR_CHAR);
  if (str == NULL || (!is_dir(args[0]) && !is_label(args[0])) ||
      args[1] != NULL)
    return (0);
  return (fill_instruction(str, zjmp, list));
}

int	check_ldi(char *str, t_list *list, char nme)
{
  int		x;
  char		**args;
  t_inst	*ldi;

  x = 0;
  if ((ldi = malloc(sizeof(t_inst))) == NULL)
    return (84);
  ldi->name = my_strndup(&nme, 1);
  if (str == NULL)
    return (0);
  args = my_str_sep(str, SEPARATOR_CHAR);
  while (args[x] != NULL) {
    if (x == 0 && !is_reg(args[x]) && !is_dir(args[x]) && !is_ind(args[x]) &&
	!is_label(args[x]))
      return (0);
    else if (x == 1 && !is_dir(args[x]) && !is_reg(args[x]) &&
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
  if ((sti = malloc(sizeof(*sti))) == NULL)
    return (84);
  sti->name = my_strndup(&nme, 1);
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
	     !is_label(args[x]))
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

  if ((fork = malloc(sizeof(t_inst))) == NULL)
    return (84);
  fork->name = my_strndup(&nme, 1);
  args = my_str_sep(str, SEPARATOR_CHAR);
  if (args[0] == NULL || (!is_dir(args[0]) && !is_label(args[0])) ||
      args[1] != NULL)
    return (0);
  return (fill_instruction(str, fork, list));
}

int	check_aff(char *str, t_list *list)
{
  t_inst	*aff;
  char		c;
  char		**args;

  c = 16;
  if ((aff = malloc(sizeof(t_inst))) == NULL)
    return (84);
  aff->name = my_strndup(&c, 1);
  args = my_str_sep(str, SEPARATOR_CHAR);
  if (args[0] == NULL || (is_reg(args[0]) != 1 && args[1] != NULL))
    return (0);
  return (fill_instruction(str, aff, list));
}
