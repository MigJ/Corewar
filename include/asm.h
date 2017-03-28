/*
** asm.h for corewar-asm in /home/laspou_k/delivery/CPE/CPE_Corewar
** 
** Made by Kévin Laspougeas
** Login   <laspou_k@epitech.net>
** 
** Started on  Mon Mar  6 18:25:42 2017 Kévin Laspougeas
** Last update Tue Mar 28 02:08:00 2017 Kévin Laspougeas
*/

#ifndef		__ASM_H__
# define	__ASM_H__

# include <fcntl.h>
# include "my.h"
# include "get_next_line.h"
# include "op.h"

typedef struct	s_instruct
{
  char			*name;
  int			addr;
  unsigned char		c_byte;
  unsigned char		**args;
  struct s_inst		*next;
  struct s_inst 	*prev;
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

# define	WRG_MNEMO	1;
# define	WRG_PAR		2;

int    		check_live(char *str, t_list *list);
int		check_ld(char *str, t_list *list, char nme);
int		check_st(char *str, t_list *list);
int		check_add_sub(char *str, t_list *list, char nme);
int		check_and(char *str, t_list *list, char nme);
int		check_zjmp(char *str, t_list *list);
int		check_ldi(char *str, t_list *list, char nme);
int		check_sti(char *str, t_list *list, char nme);
int		check_fork(char *str, t_list *list, chr nme);
int		check_aff(char *str, t_list *list);
int		fill_instruction(char *str, t_inst *to_add, t_list *list);
int		line_is_label(const char *str);
void		add_label(char *line, t_list *list, int pos);
void		exit_error(char *str, int line, int cas);

/*
**		CHAINED LISTS
*/

t_list		make_list();
void		add_to_list(t_list *list, t_inst *to_add);

#endif		/* __!ASM_H__ */
