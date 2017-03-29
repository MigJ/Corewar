/*
** my.h for  in /home/joubert/delivery/CPE_2016_corewar
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Mar 27 22:36:19 2017 Joubert Miguel
** Last update Wed Mar 29 18:03:26 2017 Joubert Miguel
*/

#ifndef _MY_H_
# define _MY_H_

/*
** LIB
*/

char    **my_str_sep(char *, char);

char	*get_next_line(const int);

char    *my_memset(int);

char    *convert10to2(unsigned char);

char    *my_strcat(char *, char *);

unsigned char           convert2to10(int);

char                    *convert10to16(int);

int     my_sign(char *);

int     my_getnbr(char *);

/*
** CHECK
*/

int     is_reg(char *);

int     is_dir(char *);

int     is_ind(char *);

int     is_label(char *);

/*
** HEADER
*/

char                    *ret_content(char *);

int     my_str_isnum(char *);

/*
** SIZE
*/

int             ret_params_size(char *);

#endif /* _MY_H_ */
