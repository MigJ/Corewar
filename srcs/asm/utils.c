/*
** utils.c for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Mar 27 22:35:07 2017 Joubert Miguel
** Last update Fri Mar 31 15:12:38 2017 Joubert Miguel
*/

#include <stdlib.h>
#include "asm.h"

char    *my_memset(int size)
{
  char  *str;
  int   i;

  if ((str = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  i = -1;
  while (++i < size)
    str[i] = 0;
  return (str);
}

char    **my_str_sep(char *str, char sep)
{
  char  **arr;
  int   i;
  int   j;
  int   k;

  if ((arr = malloc(sizeof(char *) * 30)) == NULL)
    exit (84);
  i = j = k = 0;
  while (i < 30)
    arr[i++] = my_memset(40);
  i = 0;
  while (str[i])
    {
      while (str[i] == '\t') {
	i++;
	if (str[i] != ' ' && str[i] != '\t') arr[j][k++] = ' ';
      }
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

char    *my_str_cat(char *dest, char *src)
{
  char  *res;
  int   i;
  int   j;
  int   write;

  if (dest == NULL)
    return (src);
  if (src == NULL)
    return (dest);
  j = i = 0;
  while (dest[i])
    i++;
  while (src[j])
    j++;
  if ((res = malloc(sizeof(char) * ((i + j + 1) * 100))) == NULL)
    return (NULL);
  i = -1;
  write = 0;
  while (dest[++i])
    res[write++] = dest[i];
  i = -1;
  while (src[++i])
    res[write++] = src[i];
  res[write] = '\0';
  return (res);
}
