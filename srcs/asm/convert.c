/*
** convert10to2.c for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Mar 28 01:57:24 2017 Joubert Miguel
** Last update Fri Mar 31 14:49:39 2017 Joubert Miguel
*/

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"

char			*chartab_to_char(char *hex, int nb, int *j)
{
  hex[*j] = nb / 256;
  *j += 1;
  hex[*j] = nb % 256;
  *j += 1;
  return (hex);
}

char			*int_to_char(char *hex, int nb, int *j)
{
  char			*oct;
  int			i;

  i = 0;
  oct = my_memset(3);
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
  int			i;

  i = -1;
  while (args[++i]) {
    hex[*j] = args[i];
    *j += 1;
  }
  return (hex);
}

char			*ret_content(char *line, t_inst *inst)
{
  char			*new_args;
  char			**argus;
  char			*sbs;
  int			i;
  int			j;
  int			k;

  sbs = my_memset(4);
  new_args = my_memset(ret_params_size(line) + T_LAB);
  if ((argus = malloc(sizeof(char *) * 10)) == NULL)
    return (NULL);
  argus = my_str_sep(line, SEPARATOR_CHAR);
  k = j = i = 0;
  while (argus[k]) {
    sbs = ret_size_sbs(argus[k], inst->name);
    while (sbs[i]) {
      if (sbs[i] == '1')
	new_args[j++] = argus[i][1] - 48;
      else if (sbs[i] == '2')
	new_args = chartab_to_char(new_args, my_getnbr(argus[i]), &j);
      else if (sbs[i] == '4')
	new_args = int_to_char(new_args, my_getnbr(argus[i]), &j);
      else {
	inst->lbl = my_strdup(argus[i]);
	new_args = chartab_to_char(new_args, 0, &j);
      }
      i++;
    }
    k++;
  }
  return (new_args);
}

  char			*rev_str(char *str)
  {
    int			i;
    int			j;
    char			*dest;
  
    i = strlen(str) - 1;
    j = 0;
    dest = my_memset(9);
    while (i >= 0) {
      if (!str[i])
	break;
      dest[j] = str[i];
      j++, i--;
    }
    free(str);
    return (dest);
  }

  char			*convert10to16(int nb)
  {
    char hexDigits[] = "0123456789ABCDEF";
    char *hexadecimalNumber;
    int index, remaindar;

    hexadecimalNumber = my_memset(41);
    if (nb < 0) memset(hexadecimalNumber, 'F', 8);
    nb = (unsigned char)nb;
    index = 0;
    while(nb != 0) {
      remaindar = nb % 16;
      hexadecimalNumber[index] = hexDigits[remaindar];
      nb /= 16;
      index++;
    }
    hexadecimalNumber = rev_str(hexadecimalNumber);
    return (hexadecimalNumber);
  }

  unsigned char		convert_bin_to_dec(int bin)
  {
    int			sum;
    int			rem;
    int			power;

    sum = rem = power = 0;
    while (bin > 0)
      {
	rem = bin % 10;
	bin = bin / 10;
	sum = sum + rem * pow(2,power);
	power++;
      }
    return (sum);
  }

  char		*convert10to2(unsigned char nb_char)
  {
    char		base_digits[16] =
      {'0', '1', '2', '3', '4', '5', '6', '7',
       '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char		*converted;
    int		converted_number[64];
    int		base;
    int		index;
    int		nb;
    int		i;

    i = index = 0;
    nb = nb_char;
    base = 2;
    converted = my_memset(30);
    while (nb != 0)
      {
	converted_number[index] = nb % base;
	nb = nb / base;
	++index;
      }
    --index;
    while (index>=0)
      {
	converted[i] = base_digits[converted_number[index]];
	i++, index--;
      }
    return (converted);
  }
