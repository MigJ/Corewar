/*
** get_next_line.h for gnl in /home/laspou_k/delivery/CPE/CPE_2016_getnextline
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Tue Jan  3 21:41:03 2017 Kévin Laspougeas
** Last update Wed Mar 29 23:49:14 2017 Kévin Laspougeas
*/

#ifndef		__GET_NEXT_LINE_H__
# define	__GET_NEXT_LINE_H__

#ifndef		READ_SIZE
# define	READ_SIZE (10)
#endif		/* !READ_SIZE */

#include	<unistd.h>
#include	<stdlib.h>

char		*get_next_line(const int fd);
char		*my_strncadup(char *ret, const char *buff, int n);
size_t		my_strlen(const char *str);
int		find_end(const char *str);

#endif		/* !__GET_NEXT_LINE_H__ */
