/*
** my_getnbr.c for CPoolDay_04 in /home/laspou_k/delivery
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Thu Oct  6 13:58:26 2016 Kévin Laspougeas
** Last update Sat Apr  1 17:15:26 2017 Kévin Laspougeas
*/

#include "my.h"

int	count_str(char *str)
{
  int	n;
  int	i;
  int	out;

  out = 0;
  i = 0;
  n = 0;
  while (str[n] == '+' || str[n] == '-')
    n++;
  while ((out != 1) && (str[n] != '\0'))
    {
      if (str[n] >= '0' && str[n] <= '9')
	{
	  i++;
	  n++;
	}
      else
	out = 1;
    }
  return (i);
}

int	calc_nbr(int n, int *multi, char *str, int nbr)
{
  nbr = nbr + (str[n] - '0') * *multi;
  *multi = *multi / 10;
  return (nbr);
}

int	analys_str(char *str, int multi, int i, int nbr)
{
  int	signe;
  int	n;
  int	*mult;

  mult = &multi;
  signe = 0;
  n = 0;
  while (str[n] == '+' || str[n] == '-')
    {
      if (str[n] == '+')
	signe = signe + 1;
      else if (str[n] == '-')
	signe = signe - 1;
      n++;
    }
  while ((str[n] != '\0') || (i < 1))
    {
      if ((str[n] > '9') || (str[n] < '0'))
	i = 1;
      else
	nbr = calc_nbr(n, mult, str, nbr);
      n++;
    }
  (signe < 0) ? (-nbr) : (nbr);
  return (nbr);
}

int	my_getnbr(char *str)
{
  int	i;
  int	taille;
  int	multi;
  int	nbr;

  multi = 1;
  i = 0;
  nbr = 0;
  taille = count_str(str);
  if (taille > 9)
    return (0);
  else
    {
      while (taille > 1)
	{
	  multi = multi * 10;
	  taille--;
	}
      nbr = analys_str(str, multi, i, nbr);
    }
  return (nbr);
}
