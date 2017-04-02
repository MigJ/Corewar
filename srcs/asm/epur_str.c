/*
** check_shell.c for  in /home/joubert/delivery/PSU_2016_minishell2
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 13:06:25 2017 Joubert Miguel
** Last update Sun Apr  2 17:05:42 2017 Joubert Miguel
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

char	**my_str_sep(char *str, char sep)
{
  char  **arr;
  int   i;
  int   j;
  int   k;

  if (!str) return (NULL);
  if ((arr = malloc(sizeof(char *) * 100)) == NULL)
    exit (84);
  i = j = k = 0;
  while (i < 100)
    arr[i++] = my_memset(10000);
  i = 0;
  while (str[i])
    {
      if (str[i] == COMMENT_CHAR) break;
      if (str[i] == sep)
	{
	  i++, j++;
	  k = 0;
	}
      arr[j][k] = str[i];
      k++, i++;
    }
  arr[++j] = NULL;
  return (arr);
}
