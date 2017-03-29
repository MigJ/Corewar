/*
** core.h for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Wed Mar 29 17:36:38 2017 Kévin Laspougeas
** Last update Wed Mar 29 17:58:28 2017 Kévin Laspougeas
*/

#ifndef		__CORE_H__
# define	__CORE_H__

# include <fcntl.h>
# include "op.h"

typedef struct	t_champ_header
{
  char		*name;
  char		*comment;
  int		size;
  int		start;
}st_head;

#endif		/* !__CORE_H__ */
