/*
** header.c for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Mar 27 22:00:37 2017 Kévin Laspougeas
** Last update Mon Mar 27 22:11:10 2017 Kévin Laspougeas
*/

#include <asm.h>

void	make_header(const int fd, const int fd_out)
{
  header_t	header;
  char		buff[PROG_NAME_LENGTH + COMMENT_LENGHT + 1];
  int		o;

  o = 1;
  header.magic = COREWAR_EXEC_MAGIC;
  while ((buff = get_next_line(fd)) != NULL && o == 1)
    {
      
    }
}
