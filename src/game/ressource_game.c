/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** town_game.c
*/

#include "rpg.h"
#include "chained_list.h"

static const char *STEPS = "assets/font/Steps.ttf";
static char *FIRST_TASK = "1- Find someone who wants\n\n    to talk with you !";
static char *SEC_TASK = "2- Find the diamond in the\n\n    mine !";
static char *THIRD_TASK = "3- Bring back the diamond\n\n    to the salesman !";
static char *FOURTH_TASK = "4- Speaks to the archaeologist\n\n    near the fountain !";
static char *FIFTH_TASK = "5- Find the the ancient\n\n relic in the swamp !";
static char *SIXTH_TASK = "6- Bring back the ancient\n\n relic to the archaeologist !";

void create_town_game_sprite(t_sprite **sprite)
{
    *sprite = add_sprite_inlist(*sprite, create_sprite("assets/img/People1.png",
            (sfVector2f) {125, 160}, (sfVector2f) {0.4, 0.4}),
            len_list_sprite(*sprite));
    *sprite = add_sprite_inlist(*sprite, create_sprite("assets/img/People2.png",
            (sfVector2f) {795, 45}, (sfVector2f) {0.4, 0.4}), len_list_sprite(
            *sprite));
    *sprite = add_sprite_inlist(*sprite, create_sprite("assets/img/People3.png",
            (sfVector2f) {460, 372}, (sfVector2f) {0.4, 0.4}), len_list_sprite(
            *sprite));
    *sprite = add_sprite_inlist(*sprite, create_sprite("assets/img/People4.png",
            (sfVector2f) {650, 645}, (sfVector2f) {0.4, 0.4}), len_list_sprite(
            *sprite));
}

t_rect *creat_rect_particles(void)
{
    int pos_x = 1;
    int pos_y = 0;
    t_rect *rect = NULL;

    for (int count = 0; count != 22; ++count) {
        for (int i = 0; i != 200; ++i) {
            rect = add_rectangle_inlist(rect, create_rect((sfVector2f) {pos_x, pos_y},
                (sfVector2f) {0.2, 2.5}, sfWhite, sfTransparent), len_list_rect(rect));
            pos_x += 5;
        }
        pos_x = 10 + count;
        pos_y -= 50;
    }
    return rect;
}

t_rect *create_rect_game(void)
{
    t_rect *rect = NULL;

    rect = add_rectangle_inlist(rect, create_rect((sfVector2f) {0, 0},
        (sfVector2f) {1920, 1080}, sfBlack, sfBlack), len_list_rect(rect));
    rect = add_rectangle_inlist(rect, create_rect((sfVector2f) {0, 0},
        (sfVector2f) {107, 20}, sfColor_fromRGBA(20, 20, 20, 220),
        sfWhite), len_list_rect(rect));
    return rect;
}

t_text *create_info_game_text(void)
{
    t_text *text = NULL;

    text = add_text_inlist(text, create_text(FIRST_TASK, (sfVector2f)
            {500, 300}, (sfVector2f) {0.14, 0.14}, STEPS), len_list_text(text));
    text = add_text_inlist(text, create_text(SEC_TASK, (sfVector2f)
            {500, 500}, (sfVector2f) {0.14, 0.14}, STEPS), len_list_text(text));
    text = add_text_inlist(text, create_text(THIRD_TASK, (sfVector2f)
            {500, 500}, (sfVector2f) {0.14, 0.14}, STEPS), len_list_text(text));
    text = add_text_inlist(text, create_text(FOURTH_TASK, (sfVector2f)
            {500, 500}, (sfVector2f) {0.13, 0.13}, STEPS), len_list_text(text));
    text = add_text_inlist(text, create_text(FIFTH_TASK, (sfVector2f)
            {500, 500}, (sfVector2f) {0.14, 0.14}, STEPS), len_list_text(text));
    text = add_text_inlist(text, create_text(SIXTH_TASK, (sfVector2f)
            {500, 500}, (sfVector2f) {0.14, 0.14}, STEPS), len_list_text(text));
    return text;
}
