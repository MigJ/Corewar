/*
** get_labels.c for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Mar 27 16:59:52 2017 Kévin Laspougeas
** Last update Tue Mar 28 01:10:16 2017 Kévin Laspougeas
*/

#include "asm.h"

t_list	make_list()
{
  t_list	list;

  list.first = NULL;
  list.end = NULL;
  list.size = 0;
  return (list);
}

int	line_is_label(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != LABEL_CHAR)
    i++;
  return (str[i] == '\0' ? 0 : i);
}

void	add_label(char *line, t_list *list, int pos)
{
  int		i;
  t_inst	label;

  label.addr = pos;
  while (line[i] != LABEL_CHAR)
    i++;
  label.name = my_strndup(line, i);
  add_to_list(list, &label);
}

void	add_to_list(t_list *list, t_inst *to_add)
{
  if (list->first == NULL)
    {
      list->first = to_add;
      list->last = to_add;
      to_add->next = NULL;
      to_add->prev = NULL;
    }
  else
    {
      to_add->next = NULL;
      to_add->prev = list->last;
      list->last->next = to_add;
      list->last = to_add;
    }
}
