/*
** my_strcmp.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 10:31:29 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:05:51 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	p1;

  i = 0;
  while (s1[i] || s2[i])
    {
      while (s1[i] == s2[i])
	{
	  if (s1[i] == '\0' && s2[i] == '\0')
	    return (0);
	  else if (s1[i] != '\0' && s2[i] == '\0')
	    return (-1);
	  else if (s1[i] == '\0' && s2[i] != '\0')
	    return (1);
	  i++;
	}
      if ((s1[i] > s2[i] && my_strlen(s1) == my_strlen(s2)) ||
	  (s1[i] != '\0' && s2[i] == '\0'))
	return (1);
      else if ((s2[i] > s1[i] && my_strlen(s1) == my_strlen(s2)) ||
	       (s1[i] == '\0' && s2[i] != '\0'))
	return (-1);
      i++;
    }
}
