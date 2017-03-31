/*
** size_calc.c for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Mar 28 02:24:15 2017 Joubert Miguel
** Last update Fri Mar 31 16:40:52 2017 Kévin Laspougeas
*/

#include <string.h>
#include <stdlib.h>
#include "asm.h"

int		get_size_sbs(char *sbs)
{
  int	i;
  int	ret;

  i = ret = 0;
  while (sbs[i] != '\0')
    {
      ret += sbs[i] - '0';
      i++;
    }
  return (ret);
}

int		ret_params_size(char *line)
{
  int		count;
  char		**argus;
  int		i;

  argus = my_str_sep(line, ',');
  count = 0;
  i = -1;
  while (argus[++i]) {
    if (is_reg(argus[i]) == 1)
      count += 1;
    else if (is_dir(argus[i]) == 1)
      count += 2;
    else if (is_ind(argus[i]) == 1)
      count += 4;
  }
  return (count);
}

int		ret_oct_from_line(char *line)
{
  char		**argus;
  char		*bin;
  int		i;

  i = 0;
  if ((argus = malloc(sizeof(char *) * 10)) == NULL)
    return (-1);
  bin = my_memset(9);
  argus = my_str_sep(line, ',');
  while (argus[i])
    {
      if (is_reg(argus[i]) == 1)
	bin = my_strcat(bin, "01");
      else if (is_dir(argus[i]) == 1)
	bin = my_strcat(bin, "10");
      else if (is_ind(argus[i]) == 1)
	bin = my_strcat(bin, "11");
      i++;
    }
  while (i++ != 4)
    bin = my_strcat(bin, "00");
  return (atoi(bin));
}

int		ret_oct_from_2(char *nb)
{
  int		count;
  int		i;
  int		j;
  char		*cmp;

  count = j = i = 0;
  cmp = my_memset(3);
  while (nb[i]) {
    if (i && i % 2 == 0) {
      if (!my_strcmp(cmp, "01"))
	count += 1;
      else if (!my_strcmp(cmp, "10"))
	count += 2;
      else if (!my_strcmp(cmp, "11"))
	count += 4;
      cmp = my_memset(3);
      j = 0;
    }
    cmp[j] = nb[i];
    j++, i++;
  }
  return (count);
}
