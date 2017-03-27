/*
** my_str_isalpha.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 11:04:19 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:06:23 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  if (str)
    {
      while (str[i] != '\0')
	{
	  if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
	    return (0);
	  i++;
	}
      return (1);
    }
  return (1);
}
