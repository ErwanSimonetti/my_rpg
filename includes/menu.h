/*
** EPITECH PROJECT, 2021
** menu.h
** File description:
** menu's prototype
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include "structure.h"

#ifndef MENU
#define MENU

void animate_button(sfText *text, t_window *window, t_text *buttons);
void animate_rectangles(sfRectangleShape *rect, t_window *window);
void setTextColor_Blue(t_text *buttons_option);
void setTextColor_Yellow(t_text *buttons_option);
void setTextColor_Green(t_text *buttons_option);
void setTextColor_Orange(t_text *buttons_option);
void setTextColor_Red(t_text *buttons_option);
void manage_volume(t_window *game, t_rect *rect_option, t_text
    *buttons_option_animated);
void manage_fps(t_window *game, t_text *buttons_option, t_rect
    *rect_option_animated, t_rect *rect_option);
void display_settings_menu(t_window *game, t_clock *clock, t_infoGame *info);
void display_new_game(t_window *game, t_clock *clock, t_infoGame *info);
void display_help_menu(t_window *game, t_clock *clock, t_infoGame *info);
void exit_game(t_window *game, t_clock *clock, t_infoGame *info);
void close_window(t_window *game);
void check_arrow_for_button(t_window *game, t_text *buttons);
int draw_player_name(t_window *game, t_text **name);
int check_multiple_outlinecolor(t_text *buttons, sfColor color);
int poll_event_menu(t_window *game, t_text *buttons, t_rect *rect_option);
char *find_sprite_name(t_window *game, t_rect *box);
t_text *find_fps_counter(t_text *buttons_option);
t_text *find_fps_settings(t_text *buttons_option);
t_text *find_cursor(t_text *buttons_option_animated);
t_rect *find_sound_bar(t_rect *rect_option);
t_rect *find_vsync(t_rect *rect_option_animated);

#endif /* !MENU */
