/*
** my_str_isprintable.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 11:13:32 2016 Kévin Laspougeas
** Last update Thu Nov  3 14:28:03 2016 Kévin Laspougeas
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  if (str)
    {
      while (str[i])
	{
	  if (str[i] < ' ' || str[i] == 127)
	    return (0);
	  i++;
	}
      return (1);
    }
  return (1);
}
