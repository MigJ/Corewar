/*
** my_puterror.c for puterror in ~/delivery/PSU/PSU_2016_my_sokoban
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Dec 12 10:43:54 2016 Kévin Laspougeas
** Last update Mon Dec 12 10:44:55 2016 Kévin Laspougeas
*/

#include "my.h"

void	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
}
