/*
** my_find_prime_sup.c for CPool_Day05 in /home/laspou_k/delivery/CPool_Day05
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Fri Oct  7 14:14:24 2016 Kévin Laspougeas
** Last update Mon Nov  7 16:02:11 2016 Kévin Laspougeas
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  while (my_is_prime(nb) != 1)
    nb++;
  return (nb);
}
