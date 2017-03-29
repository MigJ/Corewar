##
## Makefile for corewar in /home/laspou_k/delivery/CPE/CPE_Corewar
## 
## Made by Kévin Laspougeas
## Login   <laspou_k@epitech.net>
## 
## Started on  Mon Mar  6 18:36:18 2017 Kévin Laspougeas
## Last update Wed Mar 29 22:49:27 2017 Kévin Laspougeas
##

CC		=	gcc -g3

CFLAGS		=	-Wall -Werror -pedantic -ansi -I./include
LDFLAGS		=	-L./lib -lmy -lm

RM		=	rm -rf

ASM		=	./asm/asm

CORW		=	./corewar/corewar

SRCS_ASM	=	./srcs/asm/main.c		\
			./srcs/asm/get_next_line.c	\
			./srcs/asm/convert.c		\
			./srcs/asm/utils.c		\
			./srcs/asm/checks_1.c		\
			./srcs/asm/checks_2.c		\
			./srcs/asm/check_args.c		\
			./srcs/asm/get_size.c		\
			./srcs/asm/errors.c		\
			./srcs/asm/get_labels.c		\
			./srcs/asm/free.c		\
			./srcs/asm/writes.c		\
			./srcs/asm/fill_inst.c		\
			./srcs/asm/size_calc.c		\
			./srcs/asm/header.c		\

SRCS_CORW	=	

OBJS_ASM	=	$(SRCS_ASM:.c=.o)

OBJS_CORW	=	$(SRCS_CORW:.c=.o)

all	:	$(ASM) #$(CORW)
$(ASM)	:	$(OBJS_ASM)
	make -C ./lib/my
	if ! [ -d "./asm" ]; then 	\
		mkdir ./asm;		\
	fi
	$(CC) -o $(ASM) $(OBJS_ASM) $(LDFLAGS)
# $(CORW)	:	$(OBJS_CORW)
# 	if ! [ -d "./corewar" ]; then	\
# 		mkdir ./corewar;	\
# 	fi
# 	$(CC) -o $(CORW) $(OBJS_CORW) $(LDFLAGS)

clean	:
	make clean -C ./lib/my
	$(RM) $(OBJS_ASM)
#	$(RM) $(OBJS_CORW)

fclean	:	clean
	make fclean -C ./lib/my
	$(RM) $(ASM)
#	$(RM) $(CORW)

re	:	fclean all

.PHONY	:	all, clean, fclean, re
