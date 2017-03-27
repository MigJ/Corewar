/*
** my_strstr.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 10:01:37 2016 Kévin Laspougeas
** Last update Tue Oct 18 17:59:08 2016 Kévin Laspougeas
*/

#include "my.h"

char	*my_strstr(char *str, char *to_find)
{
  int	count;
  int	i;
  int	j;

  i = 0;
  count = 0;
  if (str && to_find)
    {
      while (str[i])
	{
	  j = 0;
	  while (str[i] == to_find[j])
	    {
	      i++;
	      j++;
	      count++;
	      if (to_find[j] == '\0')
		return (&str[i - count]);
	    }
	  i++;
	}
    }
  return (NULL);
}
