/*
** EPITECH PROJECT, 2021
** keyboard
** File description:
** arrow
*/

#include "structure.h"
#include <stdbool.h>

static const int DOWN = 0;
static const int UP = 1;

int find_switch_on_button_pos(t_text *buttons)
{
    sfColor mauve = sfColor_fromRGB(135, 85, 150);

    for (int i = 0; buttons != NULL; buttons = buttons->next, i++) {
        if (sfColor_toInteger(sfText_getOutlineColor(buttons->text)) ==
        sfColor_toInteger(mauve)) {
            return i;
        }
    }
    return -1;
}

void change_button_color(t_text *buttons, int pos, sfColor new_color, int dir)
{
    sfColor gris = sfColor_fromRGB(156, 156, 156);

    for (int i = 0; buttons != NULL; buttons = buttons->next, i++) {
        if (sfColor_toInteger(sfText_getFillColor(buttons->text)) ==
                sfColor_toInteger(gris) && i == pos) {
            if (dir == DOWN)
                buttons = buttons->next;
            else if (dir == UP)
                buttons = buttons->prev;
        }
        if (i == pos && buttons)
            sfText_setOutlineColor(buttons->text, new_color);
    }
}

void check_arrow_for_button(t_window *game, t_text *buttons)
{
    sfColor mauve = sfColor_fromRGB(135, 85, 150);
    int illuminate_button_pos = find_switch_on_button_pos(buttons);

    if (game->event.key.code == sfKeyUp) {
        change_button_color(buttons, illuminate_button_pos, sfBlack, UP);
        change_button_color(buttons, illuminate_button_pos - 1, mauve, UP);
    }
    if (game->event.key.code == sfKeyDown) {
        change_button_color(buttons, illuminate_button_pos, sfBlack, DOWN);
        change_button_color(buttons, illuminate_button_pos + 1, mauve, DOWN);
    }
}

int check_multiple_outlinecolor(t_text *buttons, sfColor color)
{
    int o = 0;
    for (; buttons != NULL; buttons = buttons->next) {
        if (sfColor_toInteger(sfText_getOutlineColor(buttons->text)) ==
            sfColor_toInteger(color))
            o++;
    }
    return o;
}
