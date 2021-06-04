/*
** EPITECH PROJECT, 2021
** open_read
** File description:
** open and read a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *open_read(char const *filename)
{
    int fd = open(filename, O_RDONLY);
    char *buffer;
    struct stat sb;
    int size = 0;

    if (fd == -1)
        return (NULL);
    if (stat(filename, &sb) == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    size = read(fd, buffer, sb.st_size);
    if (size == -1)
        return (NULL);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}
