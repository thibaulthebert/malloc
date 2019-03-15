##
## EPITECH PROJECT, 2018
## Malloc
## File description:
## project file
##

RM	=	rm -f

SRC	=	malloc.c		\
		free.c			\
		realloc.c		\
		show_alloc_mem.c	\
		utils_free.c		\
		utils_malloc.c		\
		utils.c			\
		calloc.c		\

CFLAGS	+=	-w -Wall -Wextra -fPIC -Wpadded

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) $(OBJ) -shared -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
