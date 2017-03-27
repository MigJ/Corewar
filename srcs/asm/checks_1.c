/*
** checks_1.c for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Fri Mar 24 14:54:14 2017 Kévin Laspougeas
** Last update Mon Mar 27 17:47:15 2017 Kévin Laspougeas
*/

#include "asm.h"

int	check_live(char *str, const int fd_out)
{
  int	i;
  char	buff[6];

  i = 0;
  if (str == NULL || str[0] != DIRECT_CHAR || my_strlen(str) > 2) ||
    (my_getnbr(&str[1]) <= 0 || my_getnbr(&str[1]) > 4)
    return (0);
  buff[0] = 1;
  buff[1] = buff[2] = buff[3] = 0;
  buff[4] = &str[1] - '0';
  write(fd_out, buff, 5);
  return (1);
}

int	check_ld(char *str, const int fd_out)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  if (str[i] == NULL || str[i + 1] != 'r')
    return (0);
  if (str[i + 2] == NULL || my_getnbr(&str[i + 2]) <= 0 ||
      my_getnbr(&str[i + 2]) > REG_NUMBER)
    return (0);
  str[i] = '\0';
  if (str[0] != DIRECT_CHAR && my_str_isnum(str) != 1)
    return (0);
  str[i] = SEPARATOR_CHAR;
  return (1);
}

int	check_st(char *str)
{
  int	i;

  i = 0;
  if (str == NULL || my_strlen(str) < 4 || str[0] != 'r')
    return (0);
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  if (str[i] == NULL || (my_str_isnum(&str[i + 1]) != 1 && str[i + 1] != 'r')
      || (str[i + 1] == 'r' && (my_gethbr(&str[i + 1]) <= 0 ||
				my_getnbr(&str[i + 1]) > REG_NUMBER)))
    return (0);
  str[i] = '\0';
  if (my_getnbr(&str[1]) <= 0 || my_getnbr(&str[1]) > REG_NUMBER)
    return (0);
  str[i] = SEPARATOR_CHAR;
  return (1);
}

int	check_add_sub(char *str)
{
  int	i;
  int	y;

  i = 0;
  if (str == NULL || my_strlen(str) < 8 || str[0] != 'r')
    return (0);
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  y = str[i] != NULL ? i : 0;
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  if (str[i] == NULL || str[i + 1] != 'r' || my_getnbr(&str[i + 2]) <= 0 ||
      my_getnbr(&str[i + 2]) > REG_NUMBER)
    return (0);
  str[i] = '\0';
  if (str[y + 1] != 'r' || my_getnbr(&str[y + 2]) <= 0 ||
      my_getnbr(&str[y + 2]) > REG_NUMBER)
    return (0);
  str[y] = '\0';
  if (my_getnbr(str[1]) <= 0 || my_getnbr(str[1]) > REG_NUMBER)
    return (0);
  str[i] = str[y] = SEPARATOR_CHAR;
  return (1);
}

int	check_and(char *str)
{
  int	i;
  int	y;

  i = 0;
  if (str == NULL || my_strlen(str) < 6 ||
      (str[0] != 'r' && str[0] != DIRECT_CHAR && my_str_isnum(str) != 1))
    return (0);
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  y = str[i] != NULL ? i : 0;
  while (str[i] != NULL && str[i] != SEPARATOR_CHAR)
    i++;
  if (
}
