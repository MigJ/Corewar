/*
** my_strncmp.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 10:36:58 2016 Kévin Laspougeas
** Last update Thu Mar 30 01:59:20 2017 Kévin Laspougeas
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (s1 && s2 && n > 0)
    {
      while (i < n)
	{
	  if (s1[i] == s2[i])
	    i++;
	  else
	    return (-1);
	}
      return (0);
    }
}
