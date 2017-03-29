/*
** read_header.c for corewar in /home/laspou_k/delivery/CPE/CPE_2016_corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Wed Mar 29 17:38:11 2017 Kévin Laspougeas
** Last update Wed Mar 29 22:31:45 2017 Kévin Laspougeas
*/

/* #include "core.h" */

/* void		read_header(const int fd, st_head *head) */
/* { */
/*   char		buff[PROG_NAME_LENGTH + COMMENT_LENGTH + 1]; */
/*   int		magic; */

/*   read(fd, buff, 4); */
/*   /\* if (my_getnbr_base(buff) != COREWAR_EXEC_MAGIC) *\/ */
/*   /\*   exit(84); *\/ */
/*   my_printf("%d\n", read(fd, buff, PROG_NAME_LENGTH)); */
/*   head->name = my_strdup(buff); */
/*   read(fd, buff, COMMENT_LENGTH); */
/*   head->comment = my_strdup(buff); */
/*   read(fd, buff, 1); */
/*   head->size = my_getnbr(buff); */
/* } */

/* int		main(int ac, char **av) */
/* { */
/*   int		fd; */
/*   st_head	header; */

/*   if (ac > 1) */
/*     { */
/*       if ((fd = open(av[1], O_RDONLY)) < 0) */
/* 	return (84); */
/*       read_header(fd, &header); */
/*       my_printf("Nom : %s\nCommentaire : %s\nTaille : %d\n", header.name, */
/* 		header.comment, header.size); */
/*       return (0); */
/*     } */
/* } */
