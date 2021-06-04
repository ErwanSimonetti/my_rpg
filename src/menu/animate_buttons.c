/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** animate_buttons.c
*/

#include "structure.h"
#include "menu.h"

sfBool button_hovered(sfText *text, t_window *window)
{
    int x = window->mousePos.x;
    int y = window->mousePos.y;

    sfFloatRect button = sfText_getGlobalBounds(text);
    return (sfFloatRect_contains(&button, x, y));
}

void animate_button(sfText *text, t_window *window, t_text *buttons)
{
    sfColor mauve = sfColor_fromRGB(135, 85, 150);
    sfColor pink = sfColor_fromRGB(215, 150, 235);

    if (button_hovered(text, &*window) == sfTrue &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        sfText_setOutlineColor(text, pink);
    else if (button_hovered(text, &*window) == sfTrue)
        sfText_setOutlineColor(text, mauve);
    else if (check_multiple_outlinecolor(buttons, mauve) > 1)
        sfText_setOutlineColor(text, sfBlack);
}