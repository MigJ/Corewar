/*
** my_strlen.c for CPool_Day07 in /home/laspou_k/delivery/CPool_Day07
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 14:26:50 2016 Kévin Laspougeas
** Last update Tue Jan 10 16:52:36 2017 Kévin Laspougeas
*/

#include <unistd.h>

size_t	my_strlen(const char *str)
{
  size_t	i;

  i = 0;
  if (str)
    {
      while (str[i])
	i++;
    }
  return (i);
}
