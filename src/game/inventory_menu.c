/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** inventory_menu.c
*/

#include "chained_list.h"
#include "lib.h"
#include "game.h"
#include "rpg.h"
#include "structure.h"
#include <stdlib.h>

static const char *ARTYPA = "assets/font/Artypa.ttf";
static const char *STEPS = "assets/font/Steps.ttf";

static void create_grip(t_rect *rect_base)
{
    for (float x = 300; x <= 600; x += 150) {
    rect_base = add_rectangle_inlist(rect_base, create_rect((sfVector2f) {1050,
                x}, (sfVector2f) {150, 150}, sfColor_fromRGBA(20, 20, 20,
                220), sfWhite), len_list_rect(rect_base));
    rect_base = add_rectangle_inlist(rect_base, create_rect((sfVector2f) {1200,
                x}, (sfVector2f) {150, 150}, sfColor_fromRGBA(20, 20, 20,
                220), sfWhite), len_list_rect(rect_base));
    rect_base = add_rectangle_inlist(rect_base, create_rect((sfVector2f) {1350,
                x}, (sfVector2f) {150, 150}, sfColor_fromRGBA(20, 20, 20,
                220), sfWhite), len_list_rect(rect_base));
    }
}

t_rect *create_inventory_menu_rectangle(void)
{
    t_rect *rect_base = NULL;

    rect_base = add_rectangle_inlist(rect_base, create_rect((sfVector2f) {260,
                100}, (sfVector2f) {1400, 800}, sfColor_fromRGBA(20, 20, 20,
                220), sfWhite), len_list_rect(rect_base));
    rect_base = add_rectangle_inlist(rect_base, create_rect((sfVector2f) {300,
                150}, (sfVector2f) {300, 300}, sfColor_fromRGBA(20, 20, 20,
                220), sfWhite), len_list_rect(rect_base));
    create_grip(rect_base);
    return rect_base;
}


t_sprite *create_inventory_menu_sprites(void)
{
    t_sprite *sprites = NULL;
    char *config_path = get_line_file("assets/save/player_info.txt", 3);

    sprites = add_sprite_inlist(sprites, create_sprite(config_path,
        (sfVector2f){310, 150}, (sfVector2f){0.85, 0.85}),
        len_list_sprite(sprites));
    sprites = add_sprite_inlist(sprites, create_sprite("assets/img/heart.png",
        (sfVector2f){310, 500}, (sfVector2f){0.4, 0.4}),
        len_list_sprite(sprites));
    sprites = add_sprite_inlist(sprites, create_sprite("assets/img/arm.png",
        (sfVector2f){310, 625}, (sfVector2f){0.4, 0.4}),
        len_list_sprite(sprites));
    sprites = add_sprite_inlist(sprites, create_sprite("assets/img/shield.png",
        (sfVector2f){330, 750}, (sfVector2f){1, 1}),
        len_list_sprite(sprites));
    sprites = add_sprite_inlist(sprites, create_sprite("assets/img/money.png",
        (sfVector2f){600, 260}, (sfVector2f){0.5, 0.5}),
        len_list_sprite(sprites));
    free(config_path);
    return sprites;
}

t_sprite *create_inventory_quest_sprites(void)
{
    t_sprite *sprites = NULL;

    sprites = add_sprite_inlist(sprites, create_sprite("assets/img/Crystal.png",
        (sfVector2f){1097, 340}, (sfVector2f){1, 1}),
        len_list_sprite(sprites));
    sprites = add_sprite_inlist(sprites, create_sprite("assets/img/Relic.png",
        (sfVector2f){1097, 330}, (sfVector2f){1, 1}),
        len_list_sprite(sprites));
    return sprites;
}

t_text *create_inventory_menu_button_animated(void)
{
    t_text *buttons_inventory = NULL;

    buttons_inventory = add_text_inlist(buttons_inventory, create_text(
        "Back", (sfVector2f) {890, 830}, (sfVector2f) {1, 1}, ARTYPA),
        len_list_text(buttons_inventory));
    return buttons_inventory;
}

t_text *create_inventory_menu_button(t_infoGame *info)
{
    t_text *buttons_inventory = NULL;
    char *config_path = get_line_file("assets/save/player_info.txt", 1);

    buttons_inventory = add_text_inlist(buttons_inventory, create_text(
        config_path, (sfVector2f) {700, 200}, (sfVector2f) {1, 1}, ARTYPA),
        len_list_text(buttons_inventory));
    buttons_inventory = add_text_inlist(buttons_inventory, create_text(
        my_itoc(info->player.max_health), (sfVector2f) {430, 515},
        (sfVector2f) {1, 1}, STEPS), len_list_text(buttons_inventory));
    buttons_inventory = add_text_inlist(buttons_inventory, create_text(
        my_itoc(info->player.attack), (sfVector2f) {445, 645},
        (sfVector2f) {1, 1}, STEPS), len_list_text(buttons_inventory));
    buttons_inventory = add_text_inlist(buttons_inventory, create_text(
        my_itoc(info->player.defense), (sfVector2f) {445, 765},
        (sfVector2f) {1, 1}, STEPS), len_list_text(buttons_inventory));
    buttons_inventory = add_text_inlist(buttons_inventory, create_text(
        my_itoc(info->money), (sfVector2f) {720, 280},
        (sfVector2f) {1.1, 1.1}, STEPS), len_list_text(buttons_inventory));
    free(config_path);
    return buttons_inventory;
}
