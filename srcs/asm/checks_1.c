/*
** checks_1.c for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Fri Mar 24 14:54:14 2017 Kévin Laspougeas
** Last update Tue Mar 28 01:35:56 2017 Kévin Laspougeas
*/

#include "asm.h"

int	is_reg(const char *str);
int	is_dir(const char *str);
int	is_ind(const char *str);
int	is_label(const char *str);

int	check_live(char *str, t_list *list)
{
  int		i;
  char		c;
  t_inst	live;

  i = 0;
  c = 1;
  live.name = my_strdup(&c);
  if (is_ind(str) != 1 || (my_getnbr(&str[1]) <= 0 || my_getnbr(&str[1]) > 4))
    return (0);
  live.addr = list->size - (T_IND + 1);
  return (fill_instruction(str, &live, list));
}

int	check_ld(char *str, t_list *list, char nme)
{
  int		i;
  t_inst	ld;

  i = 0;
  ld.name = my_strdup(&nme);
  if (str == NULL)
    return (0);
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  if (str[i] == NULL || is_reg(&str[i + 1]) != 1)
    return (0);
  str[i] = '\0';
  if (is_dir(str) != 1 && is_reg(str) != 1 && is_ind(str) != 1 &&
      is_label(str) != 1)
    return (0);
  str[i] = SEPARATOR_CHAR;
  return (fill_instruction(str, &st, list));
}

int	check_st(char *str, t_list *list)
{
  int		i;
  char		c;
  t_inst	st;

  i = 0;
  c = 3;
  st.name = my_strdup(&c);
  if (str == NULL || my_strlen(str) < 4 || str[0] != 'r')
    return (0);
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  if (is_ind(&str[i + 1]) != 1 && is_reg(&str[i + 1]) != 1)
    return (0);
  str[i] = '\0';
  if (is_reg(str) != 1)
    return (0);
  str[i] = SEPARATOR_CHAR;
  fill_instruction(str, &st, list);
  return (1);
}

int	check_add_sub(char *str, t_list *list, char nme)
{
  int		i;
  int		y;
  t_inst	add_sub;

  i = 0;
  add_sub.name = my_strdup(&nme);
  if (str == NULL || my_strlen(str) < 8 || str[0] != 'r')
    return (0);
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  y = str[i] != NULL ? i : 0;
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  if (is_reg(&str[i + 1]) != 1)
    return (0);
  str[i] = '\0';
  if (is_reg(&str[y + 1]) != 1)
    return (0);
  str[y] = '\0';
  if (is_reg(str) != 1)
    return (0);
  str[i] = str[y] = SEPARATOR_CHAR;
  return (fill_instruction(str, &add_sub, list));
}

int	check_and(char *str, t_list *list, char nme)
{
  int		i;
  int		y;
  t_inst	and;

  i = 0;
  and.name = my_strdup(&nme);
  if (str == NULL ||
      (str[0] != 'r' && str[0] != DIRECT_CHAR && my_str_isnum(str) != 1))
    return (0);
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  y = str[i] != NULL ? i : 0;
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  if (is_reg(&str[i + 1]) != 1)
    return (0);
  str[i] = '\0';
  if (!(is_reg(&str[y + 1]) && is_dir(&str[y + 1]) && is_ind(&str[y + 1]) &&
	is_label(&str[y + 1])))
    return (0);
  str[y] = '\0';
  if (!(is_reg(str) && is_dir(str) && is_ind(str) && is_label(str)))
    return (0);
  str[y] = str[i] = SEPARATOR_CHAR;
  return (fill_instruction(str, &and, list));
}
