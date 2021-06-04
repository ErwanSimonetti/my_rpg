/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** create_background_from_game.c
*/

#include "game.h"

sfSprite *create_background_from_game(t_infoGame *info)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromImage(info->background_pause,
        NULL);

    sfSprite_setPosition(sprite, (sfVector2f) {0, 0});
    sfSprite_setScale(sprite, (sfVector2f) {1, 1});
    sfSprite_setTexture(sprite, texture, 1);
    return sprite;
}
