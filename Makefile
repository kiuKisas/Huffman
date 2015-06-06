#
## Makefile for huffman in /home/kinoo_m/rendu/huffman
##
## Made by Martin Kinoo
## Login   <kinoo_m@epitech.net>
##
## Started on  Wed Nov 26 16:15:20 2014 Martin Kinoo
## Last update Sat May 30 18:46:44 2015 Martin Kinoo
##

NAME=		huffman

CC=		cc

ifeq ($(DEBUG), yes)
CFLAGS +=	-g
endif

RM=		rm -f

CFLAGS +=	-Wall -Wextra
CFLAGS +=	-I./inc/

SRC=		src/arg.c	\
		src/code_huffman.c	\
		src/make_huff_tree.c	\
		src/bin_list.c	\
		src/bin_writer.c	\
		src/give_me_fd.c	\
		src/dico_and_write.c	\
		src/bin_extra.c	\
		src/get_char_from_octet.c	\
		src/main.c	\
		src/decode_huffman.c	\
		src/fonctions/get_next_line.c	\
		src/fonctions/my_strdup.c	\
		src/fonctions/list.c	\
		src/fonctions/my_strncat.c	\
		src/fonctions/print_and_len.c	\
		src/fonctions/my_xmalloc.c	\
		src/fonctions/my_strcmp.c	\
		src/fonctions/my_strcat.c	\
		src/fonctions/my_strndup.c	\

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
