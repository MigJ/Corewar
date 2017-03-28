#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "./include/asm.h"
#include "./include/my.h"

int	main(int ac, char **av)
{
  int	fd;
  char	c;
  int	i;
  char	ext[] = {0,0,0,1};
  t_inst	to_wr;

  c = 11;
  i = 1;
  to_wr.name = my_strdup(&c);
  to_wr.c_byte = 120;
  to_wr.args = malloc(sizeof(char*) * 4);
  to_wr.args[0] = malloc(sizeof(char) * 1);
  to_wr.args[0][0] = 2;
  to_wr.args[1] = malloc(sizeof(char) * 2);
  to_wr.args[1][0] = 0;
  to_wr.args[1][1] = 23;
  to_wr.args[2] = malloc(sizeof(char) * 2);
  to_wr.args[2][0] = 0;
  to_wr.args[2][1] = 34;
  to_wr.args[3] = NULL;
  fd = open("./test.cor.out", O_CREAT | O_RDWR | O_TRUNC, 0666);
  write(fd, &to_wr.name[0], 1);
  write(fd, &to_wr.c_byte, 1);
  write(fd, &to_wr.args[0][0], 1);
  write(fd, to_wr.args[1], 2);
  write(fd, to_wr.args[2], 2);
  //  write(fd, &i, sizeof(int));
  close(fd);
  return (0);
}
