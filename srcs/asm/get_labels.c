/*
** get_labels.c for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Mar 27 16:59:52 2017 Kévin Laspougeas
** Last update Sun Apr  2 17:31:50 2017 Joubert Miguel
*/

#include "asm.h"

t_list	*make_list()
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->first = NULL;
  list->last = NULL;
  list->size = 0;
  return (list);
}

int	line_is_label(char *str, t_list *list)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != LABEL_CHAR)
    {
      if (str[i] == DIRECT_CHAR || str[i] == SEPARATOR_CHAR)
	return (0);
      i++;
    }
  if (str[i] == LABEL_CHAR)
    {
      str[i] = '\0';
      if (is_label_chars(str, LABEL_CHARS) != 1)
	return (exit_stage_2(str, list, WRG_LCHARS));
      str[i] = LABEL_CHAR;
    }
  return (str[i] == '\0' ? 0 : i);
}

void	add_label(char *line, t_list *list, int pos)
{
  int		i;
  t_inst	*label;

  i = 0;
  if ((label = malloc(sizeof(t_inst))) == NULL)
    return;
  label->lbl = NULL;
  label->size = 0;
  while (line[i] != LABEL_CHAR)
    i++;
  label->name = my_strndup(line, i);
  add_to_list(list, label);
}

void	add_to_list(t_list *list, t_inst *to_add)
{
  if (to_add->name[0] <= 16) {
    to_add->size += to_add->name[0] == 1 || to_add->name[0] == 9 ||
      to_add->name[0] == 12 || to_add->name[0] == 15 ? 1 : 2;
  }
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
  if (to_add->name[0] <= 16) {
    list->size += to_add->size;
  }
}

int	find_label(t_list *list, char *name)
{
  t_inst	*tmp;
  int		f;

  if (list->first != NULL)
    {
      tmp = list->first;
      while (tmp != NULL && (f = my_strcmp(name, tmp->name)) != 0)
	tmp = tmp->next;
      if (f == 0)
	return (tmp->size);
    }
  return (exit_stage_2(name, list, WRG_LABEL));
}
