/*
** my_swap.c for CPool_Day04 in /home/laspou_k/delivery/CPool_Day04
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Thu Oct  6 10:50:40 2016 Kévin Laspougeas
** Last update Tue Oct 18 09:08:07 2016 Kévin Laspougeas
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
