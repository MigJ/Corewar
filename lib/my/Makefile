##
## Makefile for CPool_Day10 in /home/laspou_k/delivery/CPool_Day10
## 
## Made by Kévin Laspougeas
## Login   <laspou_k@epitech.net>
## 
## Started on  Fri Oct 14 12:27:39 2016 Kévin Laspougeas
## Last update Tue Mar 28 03:20:07 2017 Kévin Laspougeas
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-I./ -lmy

NAME	=	libmy.a

HEADER	=	my.h

LIBCC	=	ar

LIBR	=	ranlib

SRCS	=	my_find_prime_sup.c \
		my_getnbr_base.c \
		my_getnbr.c \
		my_isneg.c \
		my_is_prime.c \
		my_power_rec.c \
		my_putchar.c \
		my_putnbr_base.c \
		my_put_nbr.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_show_wordtab.c \
		my_sort_int_tab.c \
		my_square_root.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strncpy.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strstr.c \
		my_str_to_wordtab.c \
		my_strupcase.c \
		my_swap.c \
		xmalloc.c \
		sum_stdarg.c \
		disp_stdarg.c \
		my_printf.c \
		my_showstr_oct.c \
		my_show_ptr.c \
		my_putnbr_blong.c \
		my_puterror.c	\
		my_strndup.c	\
		my_strsep.c	\

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBCC) rc $(NAME) $(OBJS)
	$(LIBR) $(NAME)
	cp $(NAME) ../
	if ! [ -d "../../include" ]; then \
		mkdir ../../include; \
	fi
	cp $(HEADER) ../../include

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
