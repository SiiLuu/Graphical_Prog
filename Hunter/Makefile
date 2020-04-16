##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile for compile my_hunter
##

SRC		=		src/my_hunter.c\
				src/my_hunter2.c\
				src/hitbox.c\
				src/use_func.c

OBJ		=		$(SRC:.c=.o)

NAME	=		my_hunter

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system

clean:
		
		rm -f src/*.o

fclean:	clean
		rm -f $(NAME)

re:		fclean all