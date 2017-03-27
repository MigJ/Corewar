/*
** my_strncpy.c for CPool_Day06 in /home/laspou_k/delivery/CPool_Day06
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Tue Oct 11 09:08:53 2016 Kévin Laspougeas
** Last update Tue Oct 18 09:06:58 2016 Kévin Laspougeas
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if (src)
    {
      while (i < n && src[i] != '\0')
	dest[i] = src[i++];
      if (src[i] == '\0' && n > i)
	dest[i] = '\0';
    }
}
