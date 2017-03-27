/*
** my_strcapitalize.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 10:54:18 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:05:28 2016 Kévin Laspougeas
*/

#include "my.h"

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[0] >= 'a' && str[0] <= 'z')
	str[0] = str[0] - 32;
      if ((str[i] < 'a' || str[i] > 'z') && str[i + 1] != '\0' &&
	  (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
	{
	  str[i + 1] = str[i + 1] - 32;
	  i++;
	  while (str[i] >= 'a' && str[i] <= 'z')
	    i++;
	}
      i++;
    }
}
