/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** main_menu_buttons.c
*/

#include "rpg.h"
#include "menu.h"
#include "structure.h"
#include <stdlib.h>

t_text *create_text(char *str, sfVector2f pos, sfVector2f scale,
const char *font_filepath)
{
    t_text *element = malloc(sizeof(*element));

    element->text = sfText_create();
    element->str = str;
    element->pos = pos;
    element->scale = scale;
    element->font_filepath = font_filepath;
    element->font = sfFont_createFromFile(element->font_filepath);
    element->next = NULL;
    element->prev = NULL;
    sfText_setString(element->text, element->str);
    sfText_setFont(element->text, element->font);
    sfText_setPosition(element->text, element->pos);
    sfText_setScale(element->text, element->scale);
    sfText_setOutlineThickness(element->text, 3);
    return element;
}

t_text *add_text_inlist(t_text *buttons, t_text *element,
int pos)
{
    t_text *prev = buttons;
    t_text *curr = buttons;

    if (pos == 0) {
        element->next = buttons;
        element->prev = NULL;
        return element;
    }
    for (int i = 0; i < pos; i += 1) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = element;
    element->prev = prev;
    element->next = curr;
    return buttons;
}

void draw_text(t_window *game, t_text *buttons)
{
    for (; buttons; buttons = buttons->next)
        sfRenderWindow_drawText(game->window, buttons->text, NULL);
}

void draw_text_animated(t_window *game, t_text *buttons)
{
    t_text *copy = buttons;

    for (; buttons; buttons = buttons->next) {
        sfRenderWindow_drawText(game->window, buttons->text, NULL);
        if (!(sfColor_toInteger(sfText_getColor(buttons->text)) ==
                sfColor_toInteger(sfColor_fromRGB(156, 156, 156))))
            animate_button(buttons->text, game, copy);
    }
}
