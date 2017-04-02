/*
** content.c for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Apr  1 18:40:41 2017 Joubert Miguel
** Last update Sun Apr  2 17:21:27 2017 Joubert Miguel
*/

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"

char			*chartab_to_char(char *hex, int nb, int *j)
{
  if (nb >= 0)
    hex[*j] = nb / 256;
  else
    hex[*j] = -1;
  *j += 1;
  hex[*j] = nb % 256;
  *j += 1;
  return (hex);
}

char			*int_to_char(char *hex, int nb, int *j)
{
  char                  *oct;
  int                   i;

  i = 0;
  oct = my_memset(10);
  while (nb > 0) {
    oct[i] = nb % 256;
    nb /= 256;
    i++;
  }
  i = 3;
  while (i >= 0) {
    hex[*j] = oct[i];
    i--, *j += 1;
  }
  return (hex);
}

char			*label_to_char(char *hex, char *args, int *j)
{
  int                   i;

  i = -1;
  while (args[++i]) {
    hex[*j] = args[i];
    *j += 1;
  }
  return (hex);
}

char			get_oct_pos(char *oct, int i)
{
  char                  sum;

  sum = 0;
  i--;
  while (i >= 0)
    {
      sum += (oct[i] - 48);
      i--;
    }
  return (sum + 49);
}

char			*ret_content(char *line, t_inst *inst)
{
  t_content		cont;

  cont = init_content(cont, line, inst);
  while (cont.sbs[cont.i]) {
    cont.pos = get_oct_pos(cont.sbs, cont.i);
    if (cont.sbs[cont.i] == '1')
      cont.new_args[cont.j++] = cont.argus[cont.i][1] - 48;
    else if (cont.sbs[cont.i] == '2')
      cont.new_args = chartab_to_char
	(cont.new_args, my_get_nbr(cont.argus[cont.i]), &cont.j);
    else if (cont.sbs [cont.i] == '4')
      cont.new_args = int_to_char
	(cont.new_args, my_get_nbr(cont.argus[cont.i]), &cont.j);
    if (is_label(cont.argus[cont.i])) {
      inst->lbl[cont.l++] =
	my_str_cat(cont.argus[cont.i], my_char_cat(",", cont.pos));
    }
    cont.i++;
  }
  return (cont.new_args);
}

