/*
** EPITECH PROJECT, 2021
** open_getline.c
** File description:
** open and recup the file content
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char *dest, char *src);

static int len_file(char *filename)
{
    FILE * fp;
    char * line = NULL;
    ssize_t size = 0;
    int nb_line = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
        return -1;
    for (; getline(&line, &size, fp) != -1; nb_line += 1);
    if (nb_line == 0)
        return -1;
    if (line)
        free(line);
    fclose(fp);
    return nb_line;
}

char **fopen_getline(char **buffer, char *filename)
{
    FILE *fp;
    char *line = NULL;
    int len = len_file(filename);
    ssize_t size = 0;

    if (len == -1)
        return (NULL);
    buffer = malloc(sizeof(char *) * (len + 1));
    fp = fopen(filename, "r");
    for (int i = 0; len != -1; i += 1) {
        len = getline(&line, &size, fp);
        if (len != -1) {
            buffer[i] = my_strdup(buffer[i], line);
            buffer[i + 1] = NULL;
        }
    }
    if (line)
        free(line);
    fclose(fp);
    return (buffer);
}
