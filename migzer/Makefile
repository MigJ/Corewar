##
## Makefile for  in /home/joubert/delivery/CPE_2016_corewar
## 
## Made by Joubert Miguel
## Login   <miguel.joubert@epitech.eu>
## 
## Started on  Mon Mar 27 23:21:37 2017 Joubert Miguel
## Last update Tue Mar 28 04:08:50 2017 Joubert Miguel
##

CC	=	gcc

BUG	=	gcc -g3

NAME	=	asm

SRC	=	src/*.c

LIB	=

CFLAGS	=	-W -Wall -Wextra -pedantic

RM	=	rm -fr

all	:	$(NAME)

$(NAME)	:

		$(CC) -o $(NAME) $(SRC) $(CFLAGS) -lm

debug :
		$(BUG) -o $(NAME) $(SRC) $(CFLAGS) -lm

clean	:

		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all
