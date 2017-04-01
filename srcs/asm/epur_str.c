/*
** check_shell.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 13:06:25 2017 Joubert Miguel
** Last update Sat Apr  1 13:14:31 2017 Joubert Miguel
*/

#include "asm.h"

char		*rm_tab(char *s)
{
  int		i;
  int		j;

  i = j = 0;
  if (s != NULL)
    {
      while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
	i++;
      return (s[i] == '\0' ? s : &s[i]);
    }
  return (NULL);
}

char		*epu(char *s)
{
  char		*str;
  size_t	i;
  size_t	j;

  i = j = 0;
  if (s != NULL) {
    while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
      i++;
    str = my_memset(100);
    while (s[i] != '\0')
      {
	if (s[i] != ' ' && s[i] != '\t')
	  str[j++] = s[i];
	i++;
      }
    str[j] = 0;
    return (str);
  }
  return (NULL);
}
