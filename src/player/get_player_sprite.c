/*
** EPITECH PROJECT, 2021
** display_name
** File description:
** display the game
*/

#include <stdlib.h>
#include "structure.h"
#include "chained_list.h"
#include "menu.h"
#include "rpg.h"
#include "lib.h"

static const char *ARTYPA = "assets/font/Artypa.ttf";

static void create_rectangle_sprite_list(t_rect *box, t_sprite *characters)
{
    box = add_rectangle_inlist(box, create_rect((sfVector2f) {600, 450},
        (sfVector2f) {300, 300}, sfTransparent, sfWhite), len_list_rect(box));
    box = add_rectangle_inlist(box, create_rect((sfVector2f) {1000, 450},
        (sfVector2f) {300, 300}, sfTransparent, sfWhite), len_list_rect(box));
    box = add_rectangle_inlist(box, create_rect((sfVector2f) {1400, 450},
        (sfVector2f) {300, 300}, sfTransparent, sfWhite), len_list_rect(box));
    characters = add_sprite_inlist(characters,
        create_sprite("assets/img/Character2.png", (sfVector2f) {610, 450},
        (sfVector2f) {0.85, 0.85}), len_list_sprite(characters));
    characters = add_sprite_inlist(characters,
        create_sprite("assets/img/Character3.png", (sfVector2f) {1010, 450},
        (sfVector2f) {0.85, 0.85}), len_list_sprite(characters));
    characters = add_sprite_inlist(characters,
        create_sprite("assets/img/Character4.png", (sfVector2f) {1410, 450},
        (sfVector2f) {0.85, 0.85}), len_list_sprite(characters));
}

static void free_lists(t_text *name, t_rect *box, t_sprite *characters)
{
    free(name);
    free(box);
    free(characters);
}

static void draw_lists(t_window *game, t_text *name, t_rect *box, t_sprite
    *characters)
{
    draw_rectangle_animated(game, box);
    draw_text(game, name);
    draw_sprite(&game->window, characters);
}

static char *manage_poll_event(t_window *game, char *sprite_name, t_rect *box)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtMouseButtonReleased
            && game->event.mouseButton.button == sfMouseLeft) {
            sprite_name = find_sprite_name(game, box);
            if (sprite_name != NULL)
                return sprite_name;
        }
        if (game->event.type == sfEvtClosed)
            close_window(game);
    }
    return NULL;
}

char *get_player_sprite(t_window *game)
{
    t_text *name = create_text("Choose your character", (sfVector2f) {650,
            250}, (sfVector2f) {1, 1}, ARTYPA);
    t_rect *box = create_rect((sfVector2f) {200, 450},
            (sfVector2f) {300, 300}, sfTransparent, sfWhite);
    t_sprite *characters = create_sprite("assets/img/Character1.png",
            (sfVector2f) {210, 450}, (sfVector2f) {0.85, 0.85});

    char *sprite_name = NULL;
    create_rectangle_sprite_list(box, characters);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        sprite_name = manage_poll_event(game, sprite_name, box);
        if (sprite_name)
            return sprite_name;
        draw_lists(game, name, box, characters);
        manage_window_info(game);
        sfRenderWindow_display(game->window);
    }
    free_lists(name, box, characters);
    return NULL;
}
