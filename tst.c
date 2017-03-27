#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
  int	fd;
  char	c;
  int	i;

  c = 1;
  i = 0x1;
  fd = open("./test.cor.out", O_CREAT | O_RDWR | O_TRUNC, 0666);
  write(fd, &c, sizeof(char));
  write(fd, &i, sizeof(int*));
  printf("%x\n%x\n", 2, -2);
  close(fd);
  return (0);
}
