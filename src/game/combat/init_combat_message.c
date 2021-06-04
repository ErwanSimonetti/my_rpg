/*
** EPITECH PROJECT, 2021
** display_combat_message.c
** File description:
** display
*/

#include "rpg.h"

sfText *init_combat_message(char *string)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/Steps.ttf");

    sfText_setPosition(text, (sfVector2f) {650, 500});
    sfText_setFillColor(text, sfWhite);
    sfText_setOutlineThickness(text, 4);
    sfText_setOutlineColor(text, sfBlue);
    sfText_setCharacterSize(text, 100);
    sfText_setFont(text, font);
    sfText_setString(text, string);
    return (text);
}

sfRectangleShape *init_middle_box(void)
{
    sfRectangleShape *box = sfRectangleShape_create();
    sfVector2f position = {0, 475};
    sfVector2f size = {4000, 200};
    sfColor shade = sfColor_fromRGBA(0, 0, 0, 150);

    sfRectangleShape_setSize(box, size);
    sfRectangleShape_setPosition(box, position);
    sfRectangleShape_setFillColor(box, shade);
    return (box);
}