/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** len_list_sprite.c
*/

#include "structure.h"

int len_list_sprite(t_sprite *list)
{
    int i = 0;

    for (; list; i += 1)
        list = list->next;
    return i;
}