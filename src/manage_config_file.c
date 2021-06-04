/*
** EPITECH PROJECT, 2021
** manage_config_file.c
** File description:
** manage differents action about the config file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "chained_list.h"
#include "lib.h"

void write_in_config_file(char *filename, char *content[])
{
    int fd = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0755);

    if (fd < 0)
        return;
    for (int i = 0; content[i]; i += 1) {
        write(fd, content[i], my_strlen(content[i]));
        write(fd, "\n", 1);
    }
}

void add_to_config_file(char *filename, char *content[])
{
    int fd = open(filename, O_RDWR);

    if (fd < 0)
        return;
    for (int i = 0; content[i]; i += 1) {
        write(fd, content[i], my_strlen(content[i]));
        write(fd, "\n", 1);
    }
}

sfIntRect find_area(char *config_str, int state)
{
    sfIntRect area = {0};
    int nb_element = 0;
    int i = 0;

    for (; config_str[i] != '\0' && config_str[i] != '}'; i += 1) {
        if (config_str[i] == '{' || config_str[i] == ';')
            switch (nb_element) {
            case (0):
                area.left = my_getnbr(&config_str[i + 1]);
                nb_element += 1;
                break;
            case (1):
                area.top = my_getnbr(&config_str[i + 1]);
                nb_element += 1;
                break;
            case (2):
                area.width = my_getnbr(&config_str[i + 1]);
                nb_element += 1;
                break;
            case (3):
                area.height = my_getnbr(&config_str[i + 1]);
                nb_element = 0;
                break;
            }
    }
    for (; config_str[i] != '\0'; i += 1) {
        if (config_str[i] == '{')
            area.left += state * my_getnbr(&config_str[i]);
        else if (config_str[i] == ';')
            area.top += state * my_getnbr(&config_str[i]);
    }
    return area;
}

sfVector2f get_rect_pos(char *str)
{
    sfVector2f pos = {0};
    int i = 0;

    pos.x = (float)my_getnbr(str);
    while (str[i] != '\0' && str[i] != ';')
        ++i;
    pos.y = (float)my_getnbr(&str[i]);
    return pos;
}

sfVector2f get_rect_size(char *str)
{
    sfVector2f size = {0};
    int i = 0;

    while (str[i] != '\0' && str[i] != ';')
        ++i;
    ++i;
    while (str[i] != '\0' && str[i] != ';')
        ++i;
    ++i;
    size.x = (float)my_getnbr(&str[i]);
    while (str[i] != '\0' && str[i] != ';')
        ++i;
    size.y = (float)my_getnbr(&str[i]);
    return size;
}

void create_box_from_config(char **config, t_rect **box)
{
    sfColor blue = sfColor_fromRGBA(0, 192, 192, 125);
    sfColor color = blue;

    for (int i = 0; config[i]; ++i) {
        if (config[i][0] == 'r') {
            color = sfRed;
            config[i]++;
        } else if (config[i][0] == 'b') {
            color = sfBlue;
            config[i]++;
        } else if (config[i][0] == 'g') {
            color = sfGreen;
            config[i]++;
        } else if (config[i][0] == 'n') {
            color = sfBlack;
            config[i]++;
        } else
            color = blue;
        *box = add_rectangle_inlist(*box, create_rect(get_rect_pos(config[i]),
            get_rect_size(config[i]), color, color), len_list_rect(*box));
    }
}
