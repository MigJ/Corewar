/*
** asm.h for corewar-asm in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Mar  6 18:25:42 2017 Kévin Laspougeas
** Last update Thu Mar 30 01:06:48 2017 Kévin Laspougeas
*/

#ifndef		__ASM_H__
# define	__ASM_H__

# include <fcntl.h>
# include <string.h>
# include "my.h"
# include "get_next_line.h"
# include "op.h"

typedef struct	s_instruct
{
  char			*name;
  unsigned char		c_byte;
  int			size;
  char			*args;
  struct s_instruct	*next;
  struct s_instruct	*prev;
}t_inst;

typedef struct	s_list
{
  t_inst		*first;
  t_inst		*last;
  int			size;
}t_list;

/*
**	       	ERROR_HANDLING AND PARSING
*/

# define	WRG_MNEMO	1
# define	WRG_PAR		2
# define	WRG_LABEL	3
# define	WRG_LCHARS	4

int    		check_live(char *str, t_list *list);
int		check_ld(char *str, t_list *list, char nme);
int		check_st(char *str, t_list *list);
int		check_add_sub(char *str, t_list *list, char nme);
int		check_and(char *str, t_list *list, char nme);
int		check_zjmp(char *str, t_list *list);
int		check_ldi(char *str, t_list *list, char nme);
int		check_sti(char *str, t_list *list, char nme);
int		check_fork(char *str, t_list *list, char nme);
int		check_aff(char *str, t_list *list);
int		fill_instruction(char *str, t_inst *to_add, t_list *list);
int		line_is_label(char *str, t_list *list);
int		exit_stage_2(char *name, t_list *list, int cas);
int		is_label_chars(char *str, const char *l_chars);
void		add_label(char *line, t_list *list, int pos);
void		exit_error(char *str, int line, int cas);
void		get_size(char *str, t_inst *inst, t_list *list);

/*
**		CHAINED LISTS
*/

t_list		*make_list();
void		add_to_list(t_list *list, t_inst *to_add);
int		find_label(t_list *list, char *name);
char		**my_str_sep(char*, char);
char		*my_memset(int);


/*
**		COMPILATION
*/

char		*ret_content(char *line);
int		ret_params_size(char *line);
unsigned char	convert_bin_to_dec(int nb);
int		ret_oct_from_line(char *line);
int		is_dir(char *line);
int		is_reg(char *line);
int		is_ind(char *line);
char		*my_memset(int);
char		**my_strsep(char *str, char sep);

/*
**		OUTPUT TO FILE
*/

void		create_header(const int fd, const int fd_out, header_t *head);
void		write_inst(t_inst *inst, const int fd_out);
void		write_it_all(t_list *list, const int fd_out);

/*
**		FREES
*/

void		free_list(t_list *list);

#endif		/* __!ASM_H__ */
