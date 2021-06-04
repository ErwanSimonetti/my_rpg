/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** game.h
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "structure.h"

#ifndef GAME
#define GAME

static const int UP = 1;
static const int RIGHT = 2;
static const int DOWN = 3;
static const int LEFT = 4;

void get_sprite(t_clock *clock);
void get_vector(t_clock *clock, t_infoGame *info);
void test_camera(sfSprite *map, t_infoGame *info);
void change_texture(t_sprite **sprites, char *config_file, int state,
    t_infoGame *info);
void let_shop_man_talk(t_window *game, t_sprite *sprites);
void do_transition(t_window *game, sfUint8 *shade,
    sfClock *timer, t_rect *new_game);
void talk_to_people(t_window *game, t_sprite *sprites, t_infoGame *info, t_rect
    *box);
void manage_string(t_text *text, char *new_str, char const *talk,
    int pos_in_str);
int poll_event_pause(t_window *game, t_text *buttons, t_rect *box);
int poll_event_game(t_window *game, t_infoGame *info, t_clock *clock,
    t_rect *box);
int poll_event_inventory(t_window *game, t_text *buttons, t_rect *box);
int test_interaction_points(t_window *game, t_infoGame *info,
    t_rect *box, sfVector2f character_hitbox);
bool is_in_color_rect(t_sprite *sprites, t_rect *box, sfColor color);
t_text *create_inventory_menu_button(t_infoGame *info);
sfIntRect find_area(char *config_str, int state);
sfSprite *create_background_from_game(t_infoGame *info);
t_sprite *create_inventory_menu_sprites(void);
t_sprite *create_inventory_quest_sprites(void);
t_rect *creat_rect_particles(void);
void draw_informations(t_window *game, t_infoGame *info,
    t_text *informations, t_rect *rectangle);
void delete_enemy(t_sprite *sprites, t_rect *box, sfColor color);

#endif /* !GAME */
