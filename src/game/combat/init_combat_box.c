/*
** EPITECH PROJECT, 2021
** init_combat_box.c
** File description:
** init_combat_box
*/

#include "rpg.h"

void init_combat_box(sfRectangleShape *box)
{
    sfColor fill = sfColor_fromRGBA(0, 0, 0, 100);
    sfVector2f position = {175, 675};
    sfVector2f size = {1580, 90};

    sfRectangleShape_setFillColor(box, fill);
    sfRectangleShape_setOutlineThickness(box, 3);
    sfRectangleShape_setOutlineColor(box, sfWhite);
    sfRectangleShape_setPosition(box, position);
    sfRectangleShape_setSize(box, size);
}

void init_health_bar(sfRectangleShape *bar, int is_max)
{
    sfColor fill = sfGreen;
    sfVector2f size = {100, 3};

    if (is_max)
        fill = sfRed;
    sfRectangleShape_setFillColor(bar, fill);
    sfRectangleShape_setSize(bar, size);
    sfRectangleShape_setOutlineThickness(bar, 3);
    sfRectangleShape_setOutlineColor(bar, sfBlack);
    sfRectangleShape_setPosition(bar, (sfVector2f) {0, 0});
}