/*
** my_show_wordtab.c for CPool_Day08 in ~/delivery/CPool_Day08/task03
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Thu Oct 13 10:36:11 2016 Kévin Laspougeas
** Last update Thu Nov  3 14:25:51 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	{
	  my_putstr(tab[i++]);
	  my_putchar('\n');
	}
      return (1);
    }
  return (0);
}
