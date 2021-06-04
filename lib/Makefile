##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## lib my_rpg
##

SRC	=	$(shell find -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm -f ../$(NAME)

re: fclean all

.PHONY:	all $(NAME) clean fclean re
