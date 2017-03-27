/*
** check_args2.c for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Mar 27 23:54:16 2017 Kévin Laspougeas
** Last update Tue Mar 28 00:26:30 2017 Kévin Laspougeas
*/

#include "asm.h"

int	is_reg(const char *str);
int	is_dir(const char *str);
int	is_ind(const char *str);
int	is_label(const char *str);

int	check_zjmp(char *str, t_list *list)
{
  t_inst	zjmp;

  zjmp.name = 9;
  if (str == NULL || is_dir(str) != 1)
    return (0);
  return (fill_instruction(str, &zjmp, list));
}

int	check_ldi(char *str, t_list *list, char nme)
{
  int		i;
  int		y;
  t_inst	ldi;

  i = 0;
  ldi.name = nme;
  if (str == NULL)
    return (0);
  while (str[i] != '\0' && str[i] != SEPARATOR_CHAR)
    i++;
  y = str[i] != '\0' ? 1 : 0;
  while (str[i] != '\0' && str[i] != SEPARATOR_CHAR)
    i++;
  if (is_reg(&str[i + 1]) != 1)
    return (0);
  str[i] = '\0';
  if (is_dir(&str[y + 1]) != 1 && is_ind(&str[y + 1]) != 1)
    return (0);
  str[i] = str[y] = SEPARATOR_CHAR;
  return (fill_instruction(str, &ldi, list));
}

int	check_sti(char *str, t_list *list)
{
  int		i;
  int		y;
  t_inst	sti;

  i = 0;
  sti.name = 11;
  if (str == NULL)
    return (0);
  while (str[i] != '\0' && str[i] != SEPARATOR_CHAR)
    i++;
  y = str[i] != '\0' ? 1 : 0;
  while (str[i] != '\0' && str[i] != SEPARATOR_CHAR)
    i++;
  if (is_reg(&str[i + 1]) != 1 && is_dir(&str[i + 1]) != 1 &&
      is_ind(&str[i + 1]) != 1)
    return (0);
  str[i] = '\0';
  if (is_reg(&str[y + 1]) != 1 && is_dir(&str[y + 1]) != 1 &&
      is_ind(&str[y + 1]) != 1)
    return (0);
  str[y] = '\0';
  if (is_reg(str) != 1)
    return (0);
  str[y] = str[i] = SEPARATOR_CHAR;
  return (fill_instruction(str, &sti, list));
}

int	check_fork(char *str, t_list *list, char nme)
{
  t_inst	fork;

  fork.name = nme;
  if (is_dir(str) != 1)
    return (0);
  return (fill_instruction(str, &fork, list));
}

int	check_aff(char *str, t_list *list)
{
  t_inst	aff;

  aff.name = 16;
  if (is_reg(str) != 1)
    return (0);
  return (fill_instruction(str, &aff, list));
}
