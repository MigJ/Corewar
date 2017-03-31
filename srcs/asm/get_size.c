/*
** get_size.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Tue Mar 28 03:05:46 2017 Kévin Laspougeas
** Last update Sat Apr  1 00:19:30 2017 Kévin Laspougeas
*/

#include "asm.h"

int	is_in_twice(char *to_find, t_list *list)
{
  t_inst	*tmp;
  int		i;

  tmp = list->first;
  i = 0;
  while (tmp != NULL) {
    if (my_strstr(tmp->name, to_find) != NULL)
      i++;
    tmp = tmp->next;
    if (i > 1)
      return (1);
  }
  return (0);
}

int	is_s(char *arg)
{
  if (arg[my_strlen(arg)] == '\0' && arg[my_strlen(arg) - 1] == 's' &&
      arg[my_strlen(arg) - 2] == '.')
    return (my_strlen(arg) - 2);
  return (-1);
}

char	*out_file(char *arg)
{
  char	*out;
  int	i;

  i = -1;
  out = my_memset(my_strlen(arg));
  while (arg[++i] != '\0' && i < is_s(arg))
    out[i] = arg[i];
  out = my_strcat(out, ".cor");
  return (out);
}

int	is_in_label_char(char c, char *chars)
{
  int	i;

  i = 0;
  while (chars[i] != '\0')
    {
      if (c == chars[i])
	return (1);
      i++;
    }
  return (0);
}
