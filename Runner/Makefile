##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile for compile my_hunter
##

SRC		=		src/my_runner.c\
				src/animation.c\
				src/event.c\
				src/parallax.c\
				src/sprites_pos.c\
				src/doublon.c\
				src/use_func.c\
				src/obstacle.c\
				src/jump.c

OBJ		=		$(SRC:.c=.o)

NAME	=		my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
		
		rm -f src/*.o

fclean:	clean
		rm -f $(NAME)

re:		fclean all