/*
** utils.c for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Mar 27 22:35:07 2017 Joubert Miguel
** Last update Wed Mar 29 14:31:32 2017 Joubert Miguel
*/

#include <stdlib.h>
#include "../include/my.h"

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i]) {
    if (str[i] >= '0' && str[i] <= '9')
      i = i + 1;
    else
      return (0);
  }
  return (1);
}

int     my_sign(char *str)
{
  int   i;

  i = 0;
  while (str[i] == '-')
    i++;
  return (i % 2);
}

int     my_getnbr(char *str)
{
  int   i;
  int   sign;
  int   nb;

  i = nb = sign = 0;
  /*if ((str[0] < '0' || str[0] > '9') && str[0] != '-' && str[0] != '+')
    return (0);*/
  if (str[0] == '-') sign = my_sign(str);
  while (str[i] < '0' || str[i] > '9')
    i++;
  while (str[i] >= '0' && str[i] <= '9')
    {
      nb += str[i] - 48;
      nb *= 10;
      i++;
    }
  nb /= 10;
  if (sign == 1) nb *= -1;
  return (nb);
}

char    *my_strcat(char *dest, char *src)
{
  char  *res;
  int   i;
  int   j;
  int   write;

  j = i = 0;
  if (dest == NULL)
    return (src);
  if (src == NULL)
    return (dest);
  while (dest[i])
    i++;
  while (src[j])
    j++;
  if ((res = malloc(sizeof(char) * ((i + j + 1) * 10))) == NULL)
    return (NULL);
  i = -1;
  write = 0;
  while (dest[++i])
    res[write++] = dest[i];
  i = -1;
  while (src[++i])
    res[write++] = src[i];
  res[write] = 0;
  return (res);
}

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
