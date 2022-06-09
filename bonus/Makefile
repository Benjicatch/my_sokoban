##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC			=	sources/help.c						\
				sources/map/error_map.c				\
				sources/map/mem_alloc_2d_array.c	\
				sources/map/load_in_mem.c			\
				sources/map/sub_functions.c			\
				sources/player/player.c				\
				sources/player/find_player.c		\
				sources/player/boxes.c				\
				sources/player/move_boxes.c			\
				sources/window.c					\
				sources/lists.c						\
				sources/restart.c					\
				sources/print_map.c					\
				sources/endgame.c

SRC_MAIN	=	main.c

SRC_TESTS	=	tests/tests_project.c				\
				tests/tests_move_player.c

OBJ		=	$(SRC_MAIN:.c=.o)					\
			$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-Wall -Wextra -I./includes -g

TEST_FLAGS	=	--coverage -lcriterion

LIB		=	-L./lib -lmy -lncurses

NAME		=	my_sokoban

NAME_TEST	=	unit_tests

all:		libr $(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LIB)

tests_run:		libr
			$(CC) -o $(NAME_TEST) $(SRC_TESTS) $(SRC) $(LIB) $(TEST_FLAGS) \
			$(CFLAGS)
			./$(NAME_TEST)
			gcovr --exclude lib --exclude tests

clean:
			$(RM) $(OBJ)
			$(RM) *.gc*
			$(RM) *~
			$(MAKE) -C lib/ clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(NAME_TEST)
			$(MAKE) -C lib/ fclean

libr:
			$(MAKE) -C lib/

re:		fclean all

.PHONY: clean libr
