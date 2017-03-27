/*
** my_strncmp.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 10:36:58 2016 Kévin Laspougeas
** Last update Tue Jan 10 18:27:03 2017 Kévin Laspougeas
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (s1 && s2 && n > 0)
    {
      while (i < n)
	{
	  while (s1[i] == s2[i])
	    {
	      if (i == n || s2[i] == '\0')
		return (0);
	      else if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	      i++;
	    }
	  return (-1);
	}
    }
}
