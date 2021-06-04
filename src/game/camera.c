/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** camera.c
*/

#include "game.h"
#include "structure.h"
#include <stdlib.h>

void test_sides_x_camera(sfFloatRect map_rect, sfVector2f camera_size,
        sfVector2f camera_center, t_infoGame *info)
{
    if (camera_center.x - camera_size.x / 2 <= map_rect.left)
        sfView_setCenter(info->camera, (sfVector2f)
            {camera_center.x + (map_rect.left -
            (camera_center.x - camera_size.x / 2)),
            info->character_move.y + 23.5});
    if (camera_center.x + camera_size.x / 2 >= map_rect.left + map_rect.width)
        sfView_setCenter(info->camera, (sfVector2f)
            {camera_center.x - ((camera_center.x +
            camera_size.x / 2) - (map_rect.left +
            map_rect.width)), info->character_move.y + 23.5});
}

void test_sides_y_camera(sfFloatRect map_rect, sfVector2f camera_size,
        sfVector2f camera_center, t_infoGame *info)
{
    if (camera_center.y - camera_size.y / 2 <= map_rect.top)
        sfView_setCenter(info->camera, (sfVector2f)
            {info->character_move.x + 10, camera_center.y + (map_rect.top -
            (camera_center.y - camera_size.y / 2))});
    if (camera_center.y + camera_size.y / 2 >= map_rect.top + map_rect.height)
        sfView_setCenter(info->camera, (sfVector2f) {info->character_move.x +
        10, camera_center.y - ((camera_center.y + camera_size.y / 2) -
        (map_rect.top + map_rect.height))});
}

void test_corners_top_camera(sfFloatRect map_rect, sfVector2f camera_size,
        sfVector2f camera_center, t_infoGame *info)
{
    if (camera_center.x - camera_size.x / 2 <= map_rect.left &&
            camera_center.y - camera_size.y / 2 <= map_rect.top)
        sfView_setCenter(info->camera, (sfVector2f)
            {camera_center.x + (map_rect.left -
            (camera_center.x - camera_size.x / 2)),
            camera_center.y + (map_rect.top -
            (camera_center.y - camera_size.y / 2))});
    if (camera_center.x + camera_size.x / 2 >= map_rect.left + map_rect.width
            && camera_center.y - camera_size.y / 2 <= map_rect.top)
        sfView_setCenter(info->camera, (sfVector2f)
            {camera_center.x - ((camera_center.x +
            camera_size.x / 2) - (map_rect.left +
            map_rect.width)), camera_center.y + (map_rect.top -
            (camera_center.y - camera_size.y / 2))});
}

void test_corners_low_camera(sfFloatRect map_rect, sfVector2f camera_size,
        sfVector2f camera_center, t_infoGame *info)
{
    if (camera_center.x - camera_size.x / 2 <= map_rect.left &&
    camera_center.y + camera_size.y / 2 >= map_rect.top + map_rect.height)
        sfView_setCenter(info->camera, (sfVector2f)
            {camera_center.x + (map_rect.left -
            (camera_center.x - camera_size.x / 2)),
            camera_center.y - ((camera_center.y +
            camera_size.y / 2) - (map_rect.top +
            map_rect.height))});
    if (camera_center.x + camera_size.x / 2 >= map_rect.left + map_rect.width &&
    camera_center.y + camera_size.y / 2 >= map_rect.top + map_rect.height)
        sfView_setCenter(info->camera, (sfVector2f)
            {camera_center.x - ((camera_center.x +
            camera_size.x / 2) - (map_rect.left +
            map_rect.width)), camera_center.y - ((camera_center.y +
            camera_size.y / 2) - (map_rect.top +
            map_rect.height))});
}

void test_camera(sfSprite *map, t_infoGame *info)
{
    sfFloatRect map_rect = sfSprite_getGlobalBounds(map);
    sfVector2f camera_size = sfView_getSize(info->camera);
    sfVector2f camera_center = sfView_getCenter(info->camera);

    test_sides_x_camera(map_rect, camera_size, camera_center, info);
    test_sides_y_camera(map_rect, camera_size, camera_center, info);
    test_corners_top_camera(map_rect, camera_size, camera_center, info);
    test_corners_low_camera(map_rect, camera_size, camera_center, info);
}
