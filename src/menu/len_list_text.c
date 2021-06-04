/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** len_list_buttons.c
*/

#include "structure.h"

int len_list_text(t_text *list)
{
    int i = 0;

    for (; list; i += 1)
        list = list->next;
    return i;
}
