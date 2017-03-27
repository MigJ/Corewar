/*
** my.h for LIB in /home/laspou_k/delivery/CPool_bistro-matic/lib/my
**
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
**
** Started on  Thu Nov  3 14:23:55 2016 Kévin Laspougeas
** Last update Tue Jan 10 18:14:39 2017 Kévin Laspougeas
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

void	my_putchar(char);
int	my_isneg(int);
int	my_put_nbr(int);
int	my_swap(int*, int*);
int	my_putstr(char*);
size_t	my_strlen(const char*);
int	my_getnbr(char*);
void	my_sort_int_tab(int*, int);
int	my_power_rec(int, int);
int	my_square_root(int);
int	my_is_prime(int);
int	my_find_prime_sup(int);
char	*my_strcpy(char*, char*);
char	*my_strncpy(char*,char*, int);
char	*my_revstr(char*);
char	*my_strstr(char*, char*);
int	my_strcmp(char*, char*);
int	my_strncmp(char*, char*, int n);
char	*my_strupcase(char*);
char	*my_strlowcase(char*);
char	*my_strcapitalize(char*);
int	my_str_isalpha(char*);
int	my_str_isnum(char*);
int	my_str_islower(char*);
int	my_str_isupper(char*);
int	my_str_isprintable(char*);
int	my_showstr(char*);
int	my_showmem(char*, int);
char	*my_strcat(char*, char*);
char	*my_strncat(char*, char*, int);
void	*xmalloc(size_t);
char	**my_str_to_wordtab(char*);
int	place_base(char, char*);
char	*my_strdup(char*);
int	my_show_wordtab(char**);
int	find_mod_base(int, int);
int	my_putnbr_base(int, char*);
int	check_str_base(char*, char*);
int	my_getnbr_base(char*, char*);
int	is_alphanum(char);
int	count_str(char*);
int	calc_nbr(int, int*, char*, int);
int	analys_str(char*, int, int, int);
int	mod_find(int);
int	sum_stdarg(int, int, ...);
int	disp_stdarg(char*, ...);
void	my_puterror(char*);
char	*my_strndup(const char *str, int n);

int	my_printf(char*, ...);
int	my_showstr_oct(char*);
void	my_show_ptr(uintptr_t);
void	my_putnbr_blong(long, char*);

#endif /* MY_H_ */
