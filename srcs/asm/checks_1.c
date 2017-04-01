/*
** checks_1.c for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Fri Mar 24 14:54:14 2017 Kévin Laspougeas
** Last update Sat Apr  1 15:18:20 2017 Kévin Laspougeas
*/

#include "asm.h"

int	is_reg(char *str);
int	is_dir(char *str);
int	is_ind(char *str);
int	is_label(char *str);

int	check_live(char *str, t_list *list)
{
  char		c;
  t_inst	*live;
  char		**args;

  c = 1;
  args = my_str_sep(str, SEPARATOR_CHAR);
  live = malloc(sizeof(t_inst));
  live->name = my_strn_dup(&c, 1);
  if (is_dir(args[0]) != 1 || my_getnbr(&args[0][1]) < 0 || args[1] != NULL)
    return (0);
  return (fill_instruction(str, live, list));
}

int	check_ld(char *str, t_list *list, char nme)
{
  int		i;
  t_inst	*ld;
  char		**args;

  i = 0;
  ld = malloc(sizeof(t_inst));
  args = my_str_sep(str, SEPARATOR_CHAR);
  ld->name = my_strn_dup(&nme, 1);
  if (str == NULL)
    return (0);
  while (args[i] != NULL) {
    if (i == 0 && !is_ind(args[i]) && !is_dir(args[i]))
      return (0);
    else if (i == 1 && !is_reg(args[i]))
      return (0);
    i++;
  }
  if (i != 2)
    return (0);
  return (fill_instruction(str, ld, list));
}

int	check_st(char *str, t_list *list)
{
  int		i;
  char		**args;
  char		c;
  t_inst	*st;

  i = 0;
  c = 3;
  st = malloc(sizeof(t_inst));
  st->name = my_strn_dup(&c, 1);
  if (str == NULL)
    return (0);
  args = my_str_sep(str, SEPARATOR_CHAR);
  while (args[i] != NULL) {
    if (i == 0 && !is_reg(args[i]))
      return (0);
    else if (i == 1 && !is_reg(args[i]) && !is_ind(args[i]))
      return (0);
    i++;
  }
  if (i != 2)
    return (0);
  return (fill_instruction(str, st, list));
}

int	check_add_sub(char *str, t_list *list, char nme)
{
  int		i;
  char		**args;
  t_inst	*add_sub;

  i = 0;
  add_sub = malloc(sizeof(t_inst));
  add_sub->name = my_char_cat("", nme);
  args = my_str_sep(str, SEPARATOR_CHAR);
  if (str == NULL)
    return (0);
  while (args[i] != NULL) {
    if (!is_reg(args[i]))
      return (0);
    i++;
  }
  if (i != 3)
    return (0);
  return (fill_instruction(str, add_sub, list));
}

int	check_and(char *str, t_list *list, char nme)
{
  int		x;
  char		**args;
  t_inst	*and;

  x = 0;
  and = malloc(sizeof(t_inst));
  and->name = my_strn_dup(&nme, 1);
  if (str == NULL)
    return (0);
  args = my_str_sep(str, SEPARATOR_CHAR);
  while (args[x] != NULL) {
    if (x == 0 && !is_reg(args[x]) && !is_dir(args[x]) && !is_ind(args[x]) &&
	!is_label(args[x]))
      return (0);
    else if (x == 1 && !is_reg(args[x]) && !is_dir(args[x]) &&
	     !is_ind(args[x]) && !is_label(args[x]))
      return (0);
    else if (x == 2 && !is_reg(args[x]))
      return (0);
    x++;
  }
  if (x != 3)
    return (0);
  return (fill_instruction(str, and, list));
}
