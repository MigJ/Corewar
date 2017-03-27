/*
** my_str_islower.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 11:10:07 2016 Kévin Laspougeas
** Last update Tue Oct 18 09:05:19 2016 Kévin Laspougeas
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  if (str)
    {
      while (str[i])
	{
	  if (str[i] < 'a' || str[i] > 'z')
	    return (0);
	  i++;
	}
      return (1);
    }
  return (1);
}
