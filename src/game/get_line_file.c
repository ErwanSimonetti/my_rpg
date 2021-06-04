/*
** EPITECH PROJECT, 2021
** get_line_file.c
** File description:
** made to get name or sprite of player
*/

#include <stdlib.h>
#include "rpg.h"
#include "structure.h"

static int get_line_len(char *buffer, const int line_searched)
{
    int current_line = 1;
    int count = 0;
    int line_len = 0;

    while (current_line != line_searched) {
        if (buffer[count] == '\0')
            return (-1);
        if (buffer[count] == '\n')
            current_line += 1;
        count += 1;
    }
    while (buffer[count] != '\n' && buffer[count] != '\0') {
        count += 1;
        line_len += 1;
    }
    return (line_len + 1);
}

char *get_line_file(const char *path, const int line_searched)
{
    char *buffer = open_read(path);
    int line_len = get_line_len(buffer, line_searched);
    char *line_str = NULL;
    int count = 0;
    int count_line = 0;
    int current_line = 1;

    if (line_len == -1)
        return (NULL);
    line_str = malloc(sizeof(char) * line_len);
    while (current_line != line_searched) {
        if (buffer[count] == '\n')
            current_line += 1;
        count += 1;
    }
    while (buffer[count] != '\n' && buffer[count] != '\0') {
        line_str[count_line] = buffer[count];
        count += 1;
        count_line += 1;
    }
    line_str[count_line] = '\0';
    return (line_str);
}