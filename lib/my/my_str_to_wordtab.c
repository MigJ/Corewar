/*
** strtab.c for CPool_Day08 in /home/laspou_k/delivery/CPool_Day08/task04
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Thu Oct 13 14:42:15 2016 Kévin Laspougeas
** Last update Sun Jan 22 20:57:12 2017 Kévin Laspougeas
*/

#include "my.h"

int	is_alphanum(char c)
{
  if (c != ' ' && c != '\0')
    return (1);
  else
    return (0);
}

char	**my_str_to_wordtab(char *str)
{
  char	**to_tab;
  int	t;
  int	i;
  int	j;

  i = 0;
  t = 0;
  to_tab = xmalloc(sizeof(char*) * my_strlen(str) + 1);
  while (i < my_strlen(str))
    {
      if (is_alphanum(str[i]) == 1)
	{
	  j = 0;
	  to_tab[t] = xmalloc(sizeof(char) * my_strlen(str) + 1);
	  while (is_alphanum(str[i]) == 1)
	    to_tab[t][j++] = str[i++];
	  to_tab[t++][j] = '\0';
	}
      i++;
    }
  to_tab[t] = NULL;
  return (to_tab);
}
