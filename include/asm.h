/*
** asm.h for corewar-asm in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Mar  6 18:25:42 2017 Kévin Laspougeas
** Last update Mon Mar 27 22:22:21 2017 Kévin Laspougeas
*/

#ifndef		__ASM_H__
# define	__ASM_H__

# include <fcntl.h>
# include "my.h"
# include "get_next_line.h"
# include "op.h"

typedef struct	s_instruct
{
  char			*name;
  unsigned char		addr;
  char			**args;
  struct s_inst		*next;
  struct s_inst 	*prev;
}t_inst;

typedef struct	s_list
{
  t_label	*first;
  t_label	*last;
  int		size;
}t_list;

char	*get_next_line(const int fd);

#endif		/* __!ASM_H__ */
