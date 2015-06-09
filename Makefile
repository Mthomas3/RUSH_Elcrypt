##
## Makefile for Makefile in /home/charre_s/rendu/marvin
##
## Made by stephane  charre
## Login   <charre_s@epitech.net>
##
## Started on  Fri Jan  2 23:30:21 2015 stephane  charre
## Last update Sun Mar  1 21:00:46 2015 Thomas Martins
##

SRC	=	elcrypt.c \
		encryption/encryption.c \
		decryption/decryption.c \
		elcrypt_checks.c \
		elcrypt_read.c \
		elcrypt_key.c \
		elcrypt_calc.c \
		elcrypt_str.c \
		elcrypt_free.c \
		elcrypt_str_two.c \
		error.c \

NAME	=	elcrypt

CC	=	cc

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -pedantic -W -ansi

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

%.o:		%.c
		$(CC) -c $(CFLAGS) -o $@ $^

re:		fclean all

remake:		re
		@./$(NAME)
