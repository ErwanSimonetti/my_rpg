/*
** EPITECH PROJECT, 2021
** talk_with_people.c
** File description:
** allow to talk with people
*/

#include "structure.h"
#include "chained_list.h"
#include "menu.h"
#include "game.h"
#include "lib.h"
#include <stdbool.h>
#include <stdlib.h>

static const char *STEPS = "assets/font/Steps.ttf";

static int get_pos_in_box(t_sprite *sprites, t_rect *box)
{
    sfVector2f pos = sfSprite_getPosition(sprites->sprite);
    int i = 0;

    pos.x += 10;
    pos.y += 10;
    for (t_rect *tmp = box; tmp; tmp = tmp->next) {
        if (sfColor_toInteger(sfBlack) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(tmp->rectangle)))
            ++i;
        if (pos.x > tmp->pos.x && pos.y > tmp->pos.y &&
            pos.x < tmp->pos.x + tmp->size.x && pos.y <
            tmp->pos.y + tmp->size.y && sfColor_toInteger(sfBlack) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(tmp->rectangle)))
            return i;
    }
    return -1;
}

static char *get_people_talk(t_window *game, t_infoGame *info, int pos_in_box)
{
    char *str = NULL;

    switch (pos_in_box) {
    case (1):
        return " Please give me\n\nthe 9 credits\n\nfor this project ";
    case (2):
        return " Who are you ? ";
    case (3):
        if (info->statushistory >= 0 && info->statushistory <= 2)
            str = "I am a little bit shy\n\ntalk with someone\n\nelse first ! ";
        else if (info->statushistory >= 3 && info->statushistory <= 4) {
            if (info->statushistory == 3)
                sfSound_play(game->sfx.success_sound);
            info->statushistory = 4;
            str = concat_str("My friend tell me about\n\nyou ! If you want you can\n\n",
            "bring me back an ancient\n\nrelic located in the swamp\n\nyou'll get rewarded ! ", ' ');
        } else if (info->statushistory >= 5){
            if (info->statushistory == 5)
                sfSound_play(game->sfx.success_sound);
            info->statushistory = 6;
            str = "Demo ended ! ";
        }
        return str;
    case (4):
        if (info->statushistory == 0 || info->statushistory == 1) {
            if (info->statushistory == 0)
                sfSound_play(game->sfx.success_sound);
            info->statushistory = 1;
            str = concat_str("Hey man, if you want\n\nsome money you can go",
            "to\n\nthe mine and bring me\n\nback the diamond ! ", ' ');
        }
        else if (info->statushistory >= 2) {
            if (info->statushistory == 2)
                sfSound_play(game->sfx.success_sound);
            info->statushistory = 3;
            str = concat_str("Wow ! you are insane !\n\nIf you want, you can",
            " talk\n\nto my friend at\n\nthe fountain to\n\nget another quest !", ' ');
        }
        return str;
    }
    return NULL;
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

static t_sprite *get_sprite_to_talk(t_sprite *sprites, int pos_in_box)
{
    t_sprite *tmp = sprites->next;
    t_sprite *new = NULL;

    for (int i = 0; i < pos_in_box; ++i, tmp = tmp->next);
    switch (pos_in_box) {
    case (1):
        new = create_sprite("assets/img/face_npc3.png", (sfVector2f){tmp->pos.x,
                tmp->pos.y - 25}, (sfVector2f){0.15, 0.15});
        break;
    case (2):
        new = create_sprite("assets/img/face_npc2.png", (sfVector2f){tmp->pos.x,
                tmp->pos.y - 25}, (sfVector2f){0.15, 0.15});
        break;
    case (3):
        new = create_sprite("assets/img/face_npc4.png", (sfVector2f){tmp->pos.x,
                tmp->pos.y - 25}, (sfVector2f){0.15, 0.15});
        break;
    case (4):
        new = create_sprite("assets/img/face_npc1.png", (sfVector2f){tmp->pos.x,
                tmp->pos.y - 25}, (sfVector2f){0.15, 0.15});
        break;
    default:
        return NULL;
    }
    return new;
}

void talk_to_people(t_window *game, t_sprite *sprites, t_infoGame *info, t_rect
    *box)
{
    char const *talk = get_people_talk(game, info, get_pos_in_box(sprites->next, box));
    t_sprite *people = get_sprite_to_talk(sprites, get_pos_in_box(
        sprites->next, box));
    char *new_str = malloc(my_strlen(talk) + 1);
    float pos_in_str = 0;
    t_text *text = create_text("", (sfVector2f){people->pos.x - 53,
            people->pos.y + 2}, (sfVector2f){0.1, 0.1}, STEPS);
    sfClock *timer = sfClock_create();
    t_rect *bubble = create_rect((sfVector2f){people->pos.x - 55, people->pos.y - 4},
        (sfVector2f) {80, 35}, sfColor_fromRGBA(20, 20, 20, 220), sfWhite);

    if (my_strlen(talk) > 60) {
        sfText_setScale(text->text, (sfVector2f){0.08, 0.08});
    }
    sfRectangleShape_setOutlineThickness(bubble->rectangle, 0.75);
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
        draw_rectangle(&game->window, bubble);
        draw_sprite(&game->window, people);
        draw_text(game, text);
        sfRenderWindow_display(game->window);
    }
}
