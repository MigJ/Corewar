/*
** my_strndup.c for strndup in /home/laspou_k/delivery/PSU/PSU_2016_minishell1
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Sun Jan 22 18:01:37 2017 Kévin Laspougeas
** Last update Sat Apr  1 13:32:29 2017 Joubert Miguel
*/

#include <stdlib.h>

char	*my_strndup(const char *src, int n)
{
  char	*ret;
  int	i;

  if (src != NULL)
    {
      i = -1;
      if ((ret = malloc(sizeof(char) * (n + 2))) == NULL)
	return (NULL);
      while (++i < n)
	ret[i] = src[i];
      ret[i] = '\0';
      return (ret);
    }
  return (NULL);
}
