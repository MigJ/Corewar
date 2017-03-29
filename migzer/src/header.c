/*
** header.c for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Mar 27 22:26:45 2017 Joubert Miguel
** Last update Wed Mar 29 17:48:43 2017 Joubert Miguel
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/op.h"

static header_t		write_magic(const int fd_cor, header_t head)
{
  head.magic = COREWAR_EXEC_MAGIC;
  head.magic = ((head.magic >> 24) & 0xff) | ((head.magic << 8) & 0xff0000) |
    ((head.magic >> 8) & 0xff00) | ((head.magic << 24) & 0xff000000);
  write(fd_cor, &head.magic, sizeof(int));
  return (head);
}

static header_t		write_name(const int fd_s, const int fd_cor, header_t head)
{
  char			*name;

  name = my_memset(PROG_NAME_LENGTH + 5);
  name = get_next_line(fd_s);
  name = strdup(my_str_sep(name, '"')[1]);
  memset(head.prog_name, 0, PROG_NAME_LENGTH + 15);
  strcpy(head.prog_name, name);
  write(fd_cor, head.prog_name, PROG_NAME_LENGTH + 4);
  return (head);
}

static header_t		write_size(const int fd_cor, header_t head)
{
  head.prog_size = 23;
  head.prog_size = ((head.prog_size >> 24) & 0xff) | ((head.prog_size << 8) & 0xff0000) |
    ((head.prog_size >> 8) & 0xff00) | ((head.prog_size << 24) & 0xff000000);
  write(fd_cor, &head.prog_size, sizeof(int));
  return (head);
}

static header_t		write_comment(const int fd_s, const int fd_cor, header_t head)
{
  char			*cmt;

  cmt = my_memset(COMMENT_LENGTH + 1);
  while ((cmt = get_next_line(fd_s)))
    if (!(strncmp(".comment", cmt, 8)))
      break;
  cmt = strdup(my_str_sep(cmt, '"')[1]);
  memset(head.comment, 0, COMMENT_LENGTH + 1);
  strcpy(head.comment, cmt);
  write(fd_cor, head.comment, COMMENT_LENGTH);
  return (head);
}

void			create_header(const int fd_s, const int fd_cor, header_t *head)
{
  *head = write_magic(fd_cor, *head);
  *head = write_name(fd_s, fd_cor, *head);
  *head = write_size(fd_cor, *head);
  *head = write_comment(fd_s, fd_cor, *head);
}

int			main(int ac, char **av)
{
  /*header_t		head;
    int			fd_cor;
    int			fd_s;

    (void)ac;
    fd_s = open(av[1], O_RDONLY);
    fd_cor = open("test.cor", O_CREAT | O_RDWR, 0666);
    create_header(fd_s, fd_cor, &head);
    close(fd_s);
    close(fd_cor);*/
  ret_content("r1,65535,r1");
}
