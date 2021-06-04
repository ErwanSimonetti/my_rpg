/*
** EPITECH PROJECT, 2021
** find_player_sprite
** File description:
** find the good player sprite
*/

#include "structure.h"
#include "lib.h"

char *find_sprite_name(t_window *game, t_rect *box)
{
    char *sprite_name[] = {"assets/config_file/Actor1.txt",
        "assets/config_file/Actor2.txt", "assets/config_file/Actor3.txt",
        "assets/config_file/Actor4.txt"};

    for (int i = 0; box; box = box->next, i += 1) {
        if (game->mousePos.x >= box->pos.x && game->mousePos.y >=
            box->pos.y && game->mousePos.x <= box->pos.x + box->size.x &&
            game->mousePos.y <= box->pos.y + box->size.y)
            return sprite_name[i];
    }
    return NULL;
}

char *get_face_name(char *sprite_name)
{
    if (my_strcmp(sprite_name, "assets/config_file/Actor1.txt") == 0)
        return "assets/img/Character1.png";
    if (my_strcmp(sprite_name, "assets/config_file/Actor2.txt") == 0)
        return "assets/img/Character2.png";
    if (my_strcmp(sprite_name, "assets/config_file/Actor3.txt") == 0)
        return "assets/img/Character3.png";
    if (my_strcmp(sprite_name, "assets/config_file/Actor4.txt") == 0)
        return "assets/img/Character4.png";
    return NULL;
}
