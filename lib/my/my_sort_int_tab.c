/*
** my_sort_int_tab.c for CPool_Day04 in /home/laspou_k/delivery/CPool_Day04
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Thu Oct  6 15:35:26 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:05:01 2016 Kévin Laspougeas
*/

#include "my.h"

void	disp_tab(int *tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      my_put_nbr(tab[i++]);
      my_putchar('\n');
    }
}

void	my_sort_int_tab(int *tab, int size)
{
  int	tmp[size + 1];
  int	count;
  int	i;
  int	j;

  count = 0;
  while (count < size)
    {
      i = 0;
      j = 1;
      while (j < size)
	{
	  if (tab[i] <= tab[j])
	    j++;
	  else
	    {
	      i = j;
	      j = i + 1;
	    }
	}
      tmp[count++] = tab[i];
      tab[i] = 2147483647;
    }
  disp_tab(tmp, size);
}
