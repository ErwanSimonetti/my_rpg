/*
** EPITECH PROJECT, 2021
** talk_in_shop.c
** File description:
** manage the talking in the shop
*/

#include "structure.h"
#include "game.h"
#include "menu.h"
#include "lib.h"
#include "chained_list.h"
#include <stdbool.h>
#include <stdlib.h>

static const char *STEPS = "assets/font/Steps.ttf";

bool is_in_color_rect(t_sprite *sprites, t_rect *box, sfColor color)
{
    sfVector2f pos = sfSprite_getPosition(sprites->sprite);

    pos.x += 10;
    pos.y += 10;
    for (t_rect *tmp = box; tmp; tmp = tmp->next) {
        if (pos.x > tmp->pos.x && pos.y > tmp->pos.y &&
            pos.x < tmp->pos.x + tmp->size.x && pos.y <
            tmp->pos.y + tmp->size.y && sfColor_toInteger(color) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(tmp->rectangle)))
            return true;
    }
    return false;
}

void manage_string(t_text *text, char *new_str, char const *talk,
    int pos_in_str)
{
    if (pos_in_str == my_strlen(talk))
        return;
    sfText_setString(text->text, new_str);
    new_str[pos_in_str] = talk[pos_in_str];
    new_str[pos_in_str + 1] = '\0';
}

static int manage_event(t_window *game, char *new_str, t_text *text)
{
    if (game->event.type == sfEvtClosed) {
        close_window(game);
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyQ)
        || sfKeyboard_isKeyPressed(sfKeyD)) {
        free(new_str);
        sfText_destroy(text->text);
        free(text);
        return 1;
    }
    return 0;
}

void let_shop_man_talk(t_window *game, t_sprite *sprites)
{
    char const *talk = "Hello ! Young man !\n\nWhat do you want ! ";
    char *new_str = malloc(my_strlen(talk) + 1);
    float pos_in_str = 0;
    t_text *text = create_text("", (sfVector2f){434, 190}, (sfVector2f)
        {0.2, 0.2}, STEPS);
    sfClock *timer = sfClock_create();
    t_rect *box = create_rect((sfVector2f) {424, 180}, (sfVector2f) {150, 40},
        sfColor_fromRGBA(20, 20, 20, 220), sfWhite);
    t_sprite *man_shop = create_sprite("assets/img/shop_man.png",
        (sfVector2f){537, 182}, (sfVector2f){0.25, 0.25});

    sfRectangleShape_setOutlineThickness(box->rectangle, 0.75);
    while (sfRenderWindow_isOpen(game->window)) {
        if (manage_event(game, new_str, text) == 1)
            return;
        if (sfTime_asSeconds(sfClock_getElapsedTime(timer)) - pos_in_str / 10 >=
            0 && (int)pos_in_str < my_strlen(talk)) {
            manage_string(text, new_str, talk, (int)pos_in_str);
            ++pos_in_str;
            sfSound_play(game->sfx.typing_sound);
        }
        sfRenderWindow_clear(game->window, sfBlack);
        draw_sprite(&game->window, sprites);
        draw_rectangle(&game->window, box);
        draw_sprite(&game->window, man_shop);
        draw_text(game, text);
        sfRenderWindow_display(game->window);
    }
}
