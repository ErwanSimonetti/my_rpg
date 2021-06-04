##
## EPITECH PROJECT, 2021
## My_RPG
## File description:
## Makefile
##

SRC		=	src/main.c				\
			src/clock.c				\
			src/window.c				\
			src/window_init.c			\
			src/clock_init.c			\
			src/info_init.c				\
			src/manage_config_file.c		\
			src/menu/len_list_text.c		\
			src/menu/len_list_sprite.c		\
			src/menu/len_list_rect.c		\
			src/menu/main_menu.c			\
			src/menu/animate_buttons.c 		\
			src/menu/animate_rectangles.c 		\
			src/menu/display_help.c			\
			src/menu/display_menu.c			\
			src/menu/display_new_game.c		\
			src/menu/poll_event_menu.c		\
			src/menu/handle_volume_cursor.c 	\
			src/menu/option_menu.c			\
			src/menu/display_settings.c		\
			src/menu/find_element_list.c		\
			src/menu/help_menu.c			\
			src/menu/keyboard_arrow.c 		\
			src/menu/find_element_list_help.c	\
			src/menu/exit_game.c 			\
			src/menu/create_help_menu_buttons.c	\
			src/menu/create_option_menu_button.c	\
			src/player/get_player_name.c		\
			src/player/get_player_sprite.c		\
			src/player/find_player_sprite.c		\
			src/chained_list/rect.c			\
			src/chained_list/sprite.c		\
			src/chained_list/text.c			\
			src/save/check_save.c			\
			src/game/display_town.c			\
			src/game/poll_event_game.c		\
			src/game/display_pause.c		\
			src/game/pause_menu.c			\
			src/game/poll_event_pause.c		\
			src/game/display_pause_settings.c	\
			src/game/save_menu.c			\
			src/game/display_save_menu.c		\
			src/game/combat/combat.c 		\
			src/game/combat/entry_animation.c 	\
			src/game/combat/draw_combat.c 		\
			src/game/combat/init_combat_box.c 	\
			src/game/combat/handle_enemy_turn.c \
			src/game/combat/handle_combat_input.c 	\
			src/game/combat/combat_outcome.c 		\
			src/game/combat/init_combat_message.c 	\
			src/game/display_inventory.c 		\
			src/game/inventory_menu.c 		\
			src/game/poll_event_inventory.c 	\
			src/game/get_line_file.c 		\
			src/game/camera.c			\
			src/game/create_background_from_game.c	\
			src/game/test_teleport_point.c		\
			src/game/display_swamp.c		\
			src/game/display_mines.c		\
			src/shop/display_shop.c			\
			src/shop/talk_in_shop.c			\
			src/game/new_game_transition.c		\
			src/game/ressource_game.c		\
			src/game/talk_with_people.c		\
			src/game/transition.c

NAME    	=	my_rpg

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-Wall -Wextra -g

CPPFLAGS	=	-I./includes/

LDFLAGS		= 	-L./lib -lmy

CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

libmy:
	make -C lib/

$(NAME): libmy $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(CSFML) $(LDFLAGS) -g3

clean:
	make -C lib/ clean
	rm -f $(OBJ)
	rm -f *#
	rm -f *~

fclean:
	make -C lib/ fclean
	rm -f $(NAME) $(OBJ)
	clear

re: fclean all

.PHONY: re fclean clean all
