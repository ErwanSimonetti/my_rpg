/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** main_menu_buttons.c
*/

#include "chained_list.h"
#include "rpg.h"

static const char *ARTYPA = "assets/font/Artypa.ttf";

t_text *create_main_menu_button(void)
{
    t_text *buttons = NULL;

    buttons = add_text_inlist(buttons, create_text("New Game", (sfVector2f)
            {840, 400}, (sfVector2f) {1, 1}, ARTYPA), len_list_text(buttons));
    buttons = add_text_inlist(buttons, create_text("Load Game", (sfVector2f)
            {830, 500}, (sfVector2f) {1, 1}, ARTYPA), len_list_text(buttons));
    if (is_there_a_save() == -1)
        sfText_setColor(buttons->next->text, sfColor_fromRGB(156, 156, 156));
    buttons = add_text_inlist(buttons, create_text("Settings", (sfVector2f)
            {850, 600}, (sfVector2f) {1, 1}, ARTYPA), len_list_text(buttons));
    buttons = add_text_inlist(buttons, create_text("Help", (sfVector2f)
            {900, 700}, (sfVector2f) {1, 1}, ARTYPA), len_list_text(buttons));
    buttons = add_text_inlist(buttons, create_text("Exit", (sfVector2f)
            {905, 800}, (sfVector2f) {1, 1}, ARTYPA), len_list_text(buttons));
    return buttons;
}

t_sprite *create_main_menu_sprite(void)
{
    t_sprite *gui = NULL;

    gui = add_sprite_inlist(gui, create_sprite("assets/img/Bckgrd_menu.jpg",
        (sfVector2f) {0, 0}, (sfVector2f) {0.5, 0.48}), len_list_sprite(gui));
    return gui;
}

t_rect *create_main_menu_rectangle(void)
{
    t_rect *rect = NULL;

    rect = add_rectangle_inlist(rect, create_rect((sfVector2f) {630, 100},
        (sfVector2f) {660, 800}, sfColor_fromRGBA(20, 20, 20, 220),
        sfColor_fromRGB(255, 255, 255)), len_list_rect(rect));
    return rect;
}
