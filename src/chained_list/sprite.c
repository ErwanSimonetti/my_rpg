/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** main_menu_sprite.c
*/

#include "rpg.h"
#include "menu.h"
#include "structure.h"
#include <stdlib.h>

t_sprite *create_sprite(char *filepath, sfVector2f pos, sfVector2f scale)
{
    t_sprite *element = malloc(sizeof(*element));

    element->sprite = sfSprite_create();
    element->filepath = filepath;
    element->pos = pos;
    element->scale = scale;
    element->texture = sfTexture_createFromFile(element->filepath, NULL);
    element->next = NULL;
    element->prev = NULL;
    sfSprite_setTexture(element->sprite, element->texture, 1);
    sfSprite_setPosition(element->sprite, element->pos);
    sfSprite_setScale(element->sprite, element->scale);
    return element;
}

t_sprite *add_sprite_inlist(t_sprite *gui, t_sprite *element,
    int pos)
{
    t_sprite *prev = gui;
    t_sprite *curr = gui;

    if (pos == 0) {
        element->next = gui;
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
    return gui;
}

void draw_sprite(sfRenderWindow **window, t_sprite *gui)
{
    for (; gui; gui = gui->next)
        sfRenderWindow_drawSprite(*window, gui->sprite, NULL);
}

t_sprite *free_sprite_in_list(t_sprite *list, int pos)
{
    t_sprite *prev = list;
    t_sprite *curr = list;

    if (pos == 0) {
        curr = list->next;
        free(list);
        return (curr);
    }
    for (int i = 0; i < pos; i += 1) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    sfSprite_destroy(curr->sprite);
    free(curr);
    return (list);
}
