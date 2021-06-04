/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** info_init.c
*/

#include "lib.h"
#include "rpg.h"

static void init_combat_sprites(t_infoGame *info)
{
    sfTexture *floor_texture = sfTexture_createFromFile(
        "assets/img/combat/bg_floor/Cobblestones5.png", NULL);
    sfTexture *wall_texture = sfTexture_createFromFile(
        "assets/img/combat/bg_wall/Town2.png", NULL);
    sfTexture *enemy_texture = sfTexture_createFromFile(
        "assets/img/combat/enemy_sprites/Monster.png", NULL);
    sfIntRect enemy_rect = {479, 0, 49, 48};

    info->combat.floor = sfSprite_create();
    sfSprite_setTexture(info->combat.floor, floor_texture, 1);
    sfSprite_setScale(info->combat.floor, (sfVector2f) {1.95, 1.95});
    info->combat.wall = sfSprite_create();
    sfSprite_setTexture(info->combat.wall, wall_texture, 1);
    sfSprite_setScale(info->combat.wall, (sfVector2f) {1.95, 1.95});
    info->enemy.sprite = sfSprite_create();
    sfSprite_setTexture(info->enemy.sprite, enemy_texture, 1);
    sfSprite_setScale(info->enemy.sprite, (sfVector2f) {5, 5});
    sfSprite_setPosition(info->enemy.sprite, (sfVector2f) {1250, 300});
    sfSprite_setTextureRect(info->enemy.sprite, enemy_rect);
}

void init_combat_font(sfText *text, int category, sfVector2f position,
                        char *string)
{
    sfFont *font = sfFont_createFromFile("assets/font/Steps.ttf");
    sfColor color = sfColor_fromRGB(255, 255, 255);

    switch (category) {
        case 0:
            color = sfColor_fromRGB(84, 178, 255);
            break;
        case 1:
            color = sfColor_fromRGB(255, 84, 84);
            break;
        case 2:
            color = sfWhite;
            break;
    }
    sfText_setColor(text, color);
    sfText_setOutlineThickness(text, 2.5);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setFont(text, font);
    sfText_setString(text, string);
    sfText_setPosition(text, position);
}

static void init_fighter_info(t_infoGame *info)
{
    info->player.name = sfText_create();
    info->enemy.name = sfText_create();
    init_combat_font(info->player.name, 0, (sfVector2f) {0, 0},
    "player");
    init_combat_font(info->enemy.name, 1, (sfVector2f) {0, 0},
    "Dark Knight");
    info->player.health_bar = sfRectangleShape_create();
    info->enemy.health_bar = sfRectangleShape_create();
    info->player.max_health_bar = sfRectangleShape_create();
    info->enemy.max_health_bar = sfRectangleShape_create();
    info->player.max_health = 50;
    info->enemy.max_health = 40;
    info->player.current_health = info->player.max_health;
    info->enemy.current_health = info->enemy.max_health;
    info->player.defense = 30;
    info->enemy.defense = 40;
    info->player.attack = 30;
    info->enemy.attack = 15;
    info->player.name_len = 5;
    info->player.last_move = -1;
    info->enemy.last_move = -1;
    info->player.atk_power = 0;
    info->enemy.atk_power = 0;
    info->enemy.name_len = 11;
    info->player.big_atk_pp = 3;
    info->enemy.big_atk_pp = 3;
}

static void init_combat_hud(t_infoGame *info)
{
    info->combat.box = sfRectangleShape_create();
    init_combat_box(info->combat.box);
    init_health_bar(info->player.health_bar, 0);
    init_health_bar(info->enemy.health_bar, 0);
    init_health_bar(info->player.max_health_bar, 1);
    init_health_bar(info->enemy.max_health_bar, 1);
    info->combat.attack = sfText_create();
    info->combat.guard = sfText_create();
    info->combat.big_attack = sfText_create();
    init_combat_font(info->combat.attack, 2, (sfVector2f) {200, 700},
    "attack");
    init_combat_font(info->combat.guard, 2, (sfVector2f) {800, 700},
    "guard");
    init_combat_font(info->combat.big_attack, 2, (sfVector2f) {1400, 700},
    "super attack");
}

void info_init(t_infoGame *info)
{
    info->statushistory = 0;
    info->statusMove = 0;
    info->character_move.x = 410;
    info->character_move.y = 380;
    info->camera = sfView_create();
    info->background_pause = sfImage_create(1920, 1031);
    init_combat_sprites(info);
    init_fighter_info(info);
    init_combat_hud(info);
    info->combat.turn = 1;
    info->player.sprite = sfSprite_create();
    info->money = 0;
    info->combat.box_middle = init_middle_box();
    info->combat.you_win = init_combat_message("You win");
}
