/*
** EPITECH PROJECT, 2021
** find_list_element.c
** File description:
** find_list_element in different list
*/

#include "structure.h"

static const int BAR_SIZE = 275;
static const int VSYNC_SIZE = 30;
static const int FPS_COUNTER_POS = 1850;

t_text *find_fps_counter(t_text *buttons_option)
{
    char const *str = NULL;

    for (; buttons_option; buttons_option = buttons_option->next) {
        str = sfText_getString(buttons_option->text);
        if (str[0] >= '0' && str[0] <= '9' &&
        sfText_getPosition(buttons_option->text).x == FPS_COUNTER_POS)
            return buttons_option;
    }
    return NULL;
}

t_text *find_fps_settings(t_text *buttons_option)
{
    char const *str = NULL;

    for (; buttons_option; buttons_option = buttons_option->next) {
        str = sfText_getString(buttons_option->text);
        if (str[0] >= '0' && str[0] <= '9' &&
            !(sfText_getPosition(buttons_option->text).x == FPS_COUNTER_POS))
            return buttons_option;
    }
    return NULL;
}

t_text *find_cursor(t_text *buttons_option_animated)
{
    char const *str = NULL;

    for (; buttons_option_animated; buttons_option_animated =
        buttons_option_animated->next) {
        str = sfText_getString(buttons_option_animated->text);
        if (str[0] == 'x')
            return buttons_option_animated;
    }
    return NULL;
}

t_rect *find_sound_bar(t_rect *rect_option)
{
    for (; rect_option; rect_option = rect_option->next)
        if (sfRectangleShape_getSize(rect_option->rectangle).x == BAR_SIZE)
            return rect_option;
    return NULL;
}

t_rect *find_vsync(t_rect *rect_option_animated)
{
    for (; rect_option_animated; rect_option_animated =
            rect_option_animated->next)
        if (sfRectangleShape_getSize(rect_option_animated->rectangle).x ==
            VSYNC_SIZE)
            return rect_option_animated;
    return NULL;
}
