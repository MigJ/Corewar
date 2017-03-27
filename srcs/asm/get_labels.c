/*
** get_labels.c for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Mar 27 16:59:52 2017 Kévin Laspougeas
** Last update Mon Mar 27 17:10:39 2017 Kévin Laspougeas
*/

#include "asm.h"

t_list	get_labels(const int fd)
{
  t_list	list;
  char		buff[256];

  list->first = NULL;
  list->end = NULL;
  list->size = 0;
  while ((buff = get_next_line(fd)) != NULL)
    {
      if (is_label(buff) == 1)
	{
	  
	}
    }
}
