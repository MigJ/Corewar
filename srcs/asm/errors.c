/*
** errors.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Tue Mar 28 01:26:09 2017 Kévin Laspougeas
** Last update Wed Mar 29 23:12:41 2017 Kévin Laspougeas
*/

#include "asm.h"

void	exit_error(char *str, int line, int cas)
{
  write(2, str, my_strlen(str));
  write(2, cas == WRG_MNEMO ? " :: Unknow instruction line " :
	cas == WRG_PAR ? " :: Invalid parameter line " : "?",
	cas == WRG_MNEMO ? 28 : cas == WRG_PAR ? 27 : 1);
  my_put_nbr(line);
  write(2, "\n", 1);
  exit(84);
}

int	exit_stage_2(char *name, t_list *list, int cas)
{
  write(2, name, my_strlen(name));
  write(2, cas == WRG_LABEL ? " :: Label not found !" : cas == WRG_LCHARS ?
	" :: unauthorized label chars !" : "?",	cas == WRG_LABEL ? 21 :
	cas == WRG_LCHARS ? 30 : 1);
  write(2, "\n", 1);
  free_list(list);
  exit(84);
  return (0);
}

int	is_label_chars(char *str, const char *l_chars)
{
  int	i;
  int	j;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	{
	  j = 0;
	  while (l_chars[j] != '\0' && str[i] != l_chars[j])
	    j++;
	  if (l_chars[j] == '\0')
	    return (0);
	  i++;
	}
      return (1);
    }
  return (0);
}
