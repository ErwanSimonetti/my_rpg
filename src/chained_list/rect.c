/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** main_menu_rect.c
*/

#include "rpg.h"
#include "menu.h"
#include "structure.h"
#include <stdlib.h>

t_rect *create_rect(sfVector2f pos, sfVector2f size, sfColor colorFill, sfColor
colorOutline)
{
    t_rect *element = malloc(sizeof(*element));

    element->rectangle = sfRectangleShape_create();
    element->pos = pos;
    element->size = size;
    element->colorFill = colorFill;
    element->colorOutline = colorOutline;
    element->next = NULL;
    element->prev = NULL;
    sfRectangleShape_setPosition(element->rectangle, element->pos);
    sfRectangleShape_setSize(element->rectangle, element->size);
    sfRectangleShape_setOutlineThickness(element->rectangle, 2);
    sfRectangleShape_setFillColor(element->rectangle, element->colorFill);
    sfRectangleShape_setOutlineColor(element->rectangle, element->colorOutline);
    return element;
}

t_rect *add_rectangle_inlist(t_rect *rect, t_rect *element,
    int pos)
{
    t_rect *prev = rect;
    t_rect *curr = rect;

    if (pos == 0) {
        element->next = rect;
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
    return rect;
}

void draw_rectangle(sfRenderWindow **window, t_rect *rect)
{
    for (; rect; rect = rect->next)
        sfRenderWindow_drawRectangleShape(*window, rect->rectangle, NULL);
}

void draw_rectangle_animated(t_window *game, t_rect *rect)
{
    for (; rect; rect = rect->next) {
        sfRenderWindow_drawRectangleShape(game->window, rect->rectangle, NULL);
        animate_rectangles(rect->rectangle, game);
    }
}

t_rect *free_rect_in_list(t_rect *list, int pos)
{
    t_rect *prev = list;
    t_rect *curr = list;

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
    free(curr);
    return (list);
}
