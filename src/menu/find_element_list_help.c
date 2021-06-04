/*
** EPITECH PROJECT, 2021
** find_list_element.c
** File description:
** find_list_element in different list in help menu
*/

#include "structure.h"

void setTextColor_Blue(t_text *buttons_option)
{
    char const *str = NULL;

    for (; buttons_option; buttons_option = buttons_option->next) {
        str = sfText_getString(buttons_option->text);
        if ((str[6] == 'Z' && str[7] == ',') || str[0] == 'a')
            sfText_setColor(buttons_option->text, sfBlue);
    }
}

void setTextColor_Yellow(t_text *buttons_option)
{
    char const *str = NULL;

    for (; buttons_option; buttons_option = buttons_option->next) {
        str = sfText_getString(buttons_option->text);
        if (str[6] == 'E' && str[7] == ' ')
            sfText_setColor(buttons_option->text, sfYellow);
    }
}

void setTextColor_Green(t_text *buttons_option)
{
    char const *str = NULL;

    for (; buttons_option; buttons_option = buttons_option->next) {
        str = sfText_getString(buttons_option->text);
        if (str[6] == 'E' && str[7] == 'S')
            sfText_setColor(buttons_option->text, sfGreen);
    }
}

void setTextColor_Orange(t_text *buttons_option)
{
    char const *str = NULL;

    for (; buttons_option; buttons_option = buttons_option->next) {
        str = sfText_getString(buttons_option->text);
        if (str[6] == 'I' && str[7] == ' ')
            sfText_setColor(buttons_option->text, sfColor_fromRGB(255, 180, 0));
    }
}

void setTextColor_Red(t_text *buttons_option)
{
    char const *str = NULL;

    for (; buttons_option; buttons_option = buttons_option->next) {
        str = sfText_getString(buttons_option->text);
        if (str[6] == 'E' && str[7] == 'N')
        sfText_setColor(buttons_option->text, sfRed);
    }
}