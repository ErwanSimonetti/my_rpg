/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** save_menu.c
*/

#include "chained_list.h"
#include "lib.h"
#include "menu.h"
#include "structure.h"

static const char *ARTYPA = "assets/font/Artypa.ttf";

t_rect *create_save_menu_rectangle(void)
{
    t_rect *rect_base = NULL;

    rect_base = add_rectangle_inlist(rect_base, create_rect((sfVector2f) {630,
        100}, (sfVector2f) {660, 800}, sfColor_fromRGBA(20, 20, 20, 220),
        sfWhite), len_list_rect(rect_base));
    return rect_base;
}

t_text *create_save_menu_button_animated(void)
{
    t_text *buttons_pause = NULL;

    buttons_pause = add_text_inlist(buttons_pause, create_text("Yes",
        (sfVector2f) {800, 500}, (sfVector2f) {1, 1}, ARTYPA),
        len_list_text(buttons_pause));
    buttons_pause = add_text_inlist(buttons_pause, create_text("No",
        (sfVector2f) {1040, 500}, (sfVector2f) {1, 1}, ARTYPA),
        len_list_text(buttons_pause));
    buttons_pause = add_text_inlist(buttons_pause, create_text("Back",
        (sfVector2f) {900, 825}, (sfVector2f) {1, 1}, ARTYPA),
        len_list_text(buttons_pause));
    return buttons_pause;
}
