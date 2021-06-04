/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** rpg.h
*/

#include <SFML/Window.h>
#include "structure.h"

#ifndef RPG
#define RPG

//prototypage des fonctions de jeu

int is_there_a_save(void);
char *open_read(char const *filename);
char *get_player_name(t_window *game);
char *get_player_sprite(t_window *game);
char *get_line_file(const char *path, const int line_searched);
void window(void);
void test_display(t_window *game, t_clock *clock, t_infoGame *info);
void draw_text(t_window *game, t_text *buttons);
void draw_text_animated(t_window *game, t_text *buttons);
void draw_sprite(sfRenderWindow **window, t_sprite *gui);
void draw_rectangle(sfRenderWindow **window, t_rect *rect);
void draw_rectangle_animated(t_window *game, t_rect *rect);
void handle_volume_cursor(sfRectangleShape *rect, sfText *cursor,
        t_window *window);
void get_fps(t_clock *clock, t_text *fps);
void get_sprite(t_clock *clock);
void display_game(t_window *game, t_clock *clock, t_infoGame *info);
void move_forward(t_clock *clock, sfIntRect *spriteRect);
void move_left(t_clock *clock, sfIntRect *spriteRect);
void move_backward(t_clock *clock, sfIntRect *spriteRect);
void move_right(t_clock *clock, sfIntRect *spriteRect);
void display_pause_menu(t_window *game, t_clock *clock, t_infoGame *info);
void display_settings_pause(t_window *game, t_clock *clock, t_infoGame *info);
void display_save_menu(t_window *game, t_clock *clock, t_infoGame *info);
void display_inventory(t_window *game, t_clock *clock, t_infoGame *info);
void display_shop(t_window *game, t_clock *clock, t_infoGame *info);
void display_swamp(t_window *game, t_clock *clock, t_infoGame *info);
void display_mines(t_window *game, t_clock *clock, t_infoGame *info);
void new_game_transition(t_window *game);
void manage_window_info(t_window *game);
sfBool button_hovered(sfText *text, t_window *window);
sfBool rectangle_hovered(sfRectangleShape *rect, t_window *window);

//prototypage des fonctions d'initialisation

void window_init(t_window *game);
void clock_init(t_clock *clock);
void info_init(t_infoGame *info);
void create_town_game_sprite(t_sprite **sprite);
t_rect *create_main_menu_rectangle(void);
t_rect *create_option_menu_rectangle(void);
t_rect *create_option_menu_rectangle_animated(void);
t_rect *create_help_menu_rectangle(void);
t_rect *create_pause_menu_rectangle(void);
t_rect *create_save_menu_rectangle(void);
t_rect *create_inventory_menu_rectangle(void);
t_rect *create_rect_game(void);
t_sprite *create_main_menu_sprite(void);
t_sprite *create_option_menu_sprite(void);
t_sprite *create_help_menu_sprite1(void);
t_sprite *create_help_menu_sprite2(void);
t_text *create_main_menu_button(void);
t_text *create_option_menu_button(t_window *game);
t_text *create_option_menu_button_animated(void);
t_text *create_help_menu_button(void);
t_text *create_help_menu_button_animated(void);
t_text *create_pause_menu_button_animated(void);
t_text *create_save_menu_button_animated(void);
t_text *create_inventory_menu_button_animated(void);
t_text *create_info_game_text(void);
t_text *create_text(char *str, sfVector2f pos, sfVector2f scale,
                const char *filepath);
t_text *add_text_inlist(t_text *buttons, t_text *element, int pos);
t_sprite *create_sprite(char *filepath, sfVector2f pos, sfVector2f scale);
t_sprite *add_sprite_inlist(t_sprite *gui, t_sprite *element,
                            int pos);
t_rect *create_rect(sfVector2f pos, sfVector2f size,
        sfColor colorFill, sfColor colorOutline);
t_rect *add_rectangle_inlist(t_rect *rect, t_rect *element,
                int pos);
void create_box_from_config(char **config, t_rect **box);
char **remove_jump_line_at_end(char **buffer);

//prototypage des fonctions de combat

int display_combat(t_window *game, t_infoGame *info);
void animate_entry(t_window *game, t_infoGame *info, sfSprite *screenshot);
sfSprite *setup_background(t_window *game, t_infoGame *info);
void draw_combat_scene(t_window *game, t_infoGame *info);
void init_combat_box(sfRectangleShape *box);
void init_health_bar(sfRectangleShape *bar, int is_max);
void handle_combat_input(t_window *game, t_infoGame *info);
sfBool combat_button_hovered(sfText *text, sfRenderWindow *window);
void handle_enemy_turn(t_window *game, t_infoGame *info);
void handle_attack(t_window *game, t_infoGame *info,
            t_infoFighter *striker, t_infoFighter *striked);
int handle_combat_outcome(t_window *game, t_infoGame *info);
int change_turn(t_infoGame *info);
void reset_defense(t_infoFighter *striked);
sfText *init_combat_message(char *string);
sfRectangleShape *init_middle_box(void);

#endif /* !RPG */
