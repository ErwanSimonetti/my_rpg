/*
** EPITECH PROJECT, 2021
** animate_rectangles.c
** File description:
** made to animates rectangle shapes
*/

#include "rpg.h"

sfBool rectangle_hovered(sfRectangleShape *rect, t_window *window)
{
    int x = window->mousePos.x;
    int y = window->mousePos.y;

    sfFloatRect button = sfRectangleShape_getGlobalBounds(rect);
    return (sfFloatRect_contains(&button, x, y));
}

void animate_rectangles(sfRectangleShape *rect, t_window *window)
{
    sfColor blue = sfColor_fromRGB(3, 252, 215);
    sfColor pink = sfColor_fromRGB(215, 150, 235);

    if (rectangle_hovered(rect, &*window) == sfTrue &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        sfRectangleShape_setOutlineColor(rect, pink);
    else if (rectangle_hovered(rect, &*window) == sfTrue)
        sfRectangleShape_setOutlineColor(rect, blue);
    else
        sfRectangleShape_setOutlineColor(rect, sfWhite);
}