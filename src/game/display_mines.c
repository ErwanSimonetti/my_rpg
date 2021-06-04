/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** display_swamp.c
*/

#include "structure.h"
#include "rpg.h"
#include "lib.h"
#include "game.h"
#include "chained_list.h"

static const char *STEPS = "assets/font/Steps.ttf";

static void init_box_and_sprites(t_rect **box, t_sprite **sprites,
    char **config_character, t_infoGame *info)
{
    char **config_rectangle = NULL;

    config_rectangle = fopen_getline(config_rectangle,
        "assets/config_file/mines.txt");
    if (config_rectangle == NULL)
        return;
    config_rectangle = remove_jump_line_at_end(config_rectangle);
    create_box_from_config(&config_rectangle[1], box);
    *sprites = create_sprite(config_rectangle[0],
            (sfVector2f) {0, 0}, (sfVector2f) {0.5, 0.5});
    change_texture(&(*sprites)->next, config_character[1], 1, info);
    *sprites = add_sprite_inlist(*sprites, create_sprite(
            "assets/img/zombie.png", (sfVector2f){135, 480}, (sfVector2f){0.45,
            0.45}), len_list_sprite(*sprites));
    *sprites = add_sprite_inlist(*sprites, create_sprite(
            "assets/img/zombie.png", (sfVector2f){505, 490}, (sfVector2f){0.45,
            0.45}), len_list_sprite(*sprites));
    *sprites = add_sprite_inlist(*sprites, create_sprite(
            "assets/img/first_boss_map.png", (sfVector2f){250, 200},
            (sfVector2f){0.6, 0.6}), len_list_sprite(*sprites));
    *box = add_rectangle_inlist(*box, create_rect((sfVector2f){120, 480},
            (sfVector2f){50, 50}, sfYellow, sfYellow), len_list_rect(*box));
    *box = add_rectangle_inlist(*box, create_rect((sfVector2f){475, 480},
            (sfVector2f){80, 50}, sfYellow, sfYellow), len_list_rect(*box));
    *box = add_rectangle_inlist(*box, create_rect((sfVector2f){230, 190},
            (sfVector2f){50, 50}, sfWhite, sfWhite), len_list_rect(*box));
}

static char **init_mines_window(char **config_character, t_infoGame *info)
{
    config_character = fopen_getline(config_character,
        "assets/save/player_info.txt");
    if (*config_character == NULL)
        return NULL;
    config_character = remove_jump_line_at_end(config_character);
    sfView_setSize(info->camera, (sfVector2f){1920 / 4, 1080 / 4});
    return config_character;
}

static void do_mines_loop(t_window *game, t_sprite *sprites,
    t_rect *box, sfCircleShape *circle)
{
    sfRenderWindow_clear(game->window, sfBlack);
    draw_sprite(&game->window, sprites);
    sfRenderWindow_drawCircleShape(game->window, circle, NULL);
}

sfCircleShape *create_circle(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 100);
    sfCircleShape_setPointCount(circle, 10000);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 500);
    sfCircleShape_setOutlineColor(circle, sfBlack);
    return circle;
}

static void check_quest(t_window *game, t_infoGame *info, t_rect *box)
{
    for (t_rect *tmp = box; tmp; tmp = tmp->next) {
        if (info->character_move.x + (47 * 0.4) - 2 >= tmp->pos.x
            && info->character_move.x <= tmp->pos.x + tmp->size.x
            && info->character_move.y + (47 * 0.4) >= tmp->pos.y
            && info->character_move.y <= tmp->pos.y + tmp->size.y &&
            sfColor_toInteger(sfRed) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(tmp->rectangle))
            && info->statushistory == 1) {
                sfSound_play(game->sfx.success_sound);
                info->statushistory = 2;
                return;
            }
    }
}

static void delete_sprite(t_sprite *sprites, t_rect *box)
{
    t_sprite *better = sprites;
    int i = 0;
    int pos = 0;

    for (t_sprite *tmp = sprites; tmp; tmp = tmp->next, ++i)
        if ((tmp->pos.x - box->pos.x < better->pos.x - box->pos.x || tmp->pos.y -
            box->pos.y < better->pos.y - box->pos.y) && box->pos.x <= tmp->pos.x
            && box->pos.y <= tmp->pos.y) {
            better = tmp;
            pos = i;
        }
    sprites = free_sprite_in_list(sprites, pos);
}

void delete_enemy(t_sprite *sprites, t_rect *box, sfColor color)
{
    sfVector2f pos = sfSprite_getPosition(sprites->sprite);
    int i = 0;

    pos.x += 10;
    pos.y += 10;
    for (t_rect *tmp = box; tmp; tmp = tmp->next, ++i)
        if (pos.x > tmp->pos.x && pos.y > tmp->pos.y &&
            pos.x < tmp->pos.x + tmp->size.x && pos.y <
            tmp->pos.y + tmp->size.y && sfColor_toInteger(color) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(tmp->rectangle))) {
            delete_sprite(sprites, tmp);
            box = free_rect_in_list(box, i);
            return;
        }
}

static void manage_combat(t_window *game, t_infoGame *info, t_sprite *sprites,
    t_rect *box)
{
    sfTexture *bg_wall;
    sfTexture *bg_floor;

    if (is_in_color_rect(sprites->next, box, sfYellow)) {
        bg_wall = sfTexture_createFromFile(
            "assets/img/combat/bg_wall/RockCave.png", NULL);
        bg_floor = sfTexture_createFromFile(
            "assets/img/combat/bg_floor/RockCave.png", NULL);
        sfSprite_setTexture(info->combat.wall, bg_wall, 1);
        sfSprite_setTexture(info->combat.floor, bg_floor, 1);
        info->enemy.sprite = create_sprite("assets/img/zombie.png",
            (sfVector2f){1250, 300}, (sfVector2f){5, 5})->sprite;
        info->enemy.name = create_text("Zombie", (sfVector2f){0, 0},
            (sfVector2f){1, 1}, STEPS)->text;
        sfText_setColor(info->enemy.name, sfColor_fromRGB(255, 84, 84));
        info->enemy.defense = 25;
        info->enemy.attack = 15;
        if (display_combat(game, info) == 1) {
            delete_enemy(sprites->next, box, sfYellow);
            sfView_setSize(info->camera, (sfVector2f){1920 / 4, 1080 / 4});
        }
    }
    if (is_in_color_rect(sprites->next, box, sfWhite)) {
        info->enemy.sprite = create_sprite("assets/img/first_boss.png",
            (sfVector2f){1000, 300}, (sfVector2f){7, 7})->sprite;
        info->enemy.name = create_text("Balrog", (sfVector2f){0, 0},
            (sfVector2f){1, 1}, STEPS)->text;
        sfText_setColor(info->enemy.name, sfColor_fromRGB(255, 84, 84));
        info->enemy.defense = 55;
        if (display_combat(game, info) == 1) {
            delete_enemy(sprites->next, box, sfWhite);
            sfView_setSize(info->camera, (sfVector2f){1920 / 4, 1080 / 4});
        }
    }
}

void display_mines(t_window *game, t_clock *clock, t_infoGame *info)
{
    int event = 0;
    sfUint8 shade = 255;
    char **config_character = NULL;
    t_rect *box = NULL;
    t_sprite *sprites = NULL;
    sfClock *timer = sfClock_create();
    sfCircleShape *circle = create_circle();
    t_rect *new_game = create_rect((sfVector2f) {0, 0}, (sfVector2f) {1920, 1080},
        sfBlack, sfBlack);
    t_text *informations = create_info_game_text();
    t_rect *game_rect = create_rect_game();

    config_character = init_mines_window(config_character, info);
    init_box_and_sprites(&box, &sprites, config_character, info);
    while (sfRenderWindow_isOpen(game->window)) {
        event = poll_event_game(game, info, clock, box);
        if (event == 1)
            return;
        else if (event == 2)
            change_texture(&sprites->next, config_character[1],
                clock->spriteStatus - 1, info);
        manage_combat(game, info, sprites, box);
        sfView_setCenter(info->camera, (sfVector2f) {info->character_move.x +
                    10, info->character_move.y + 23.5});
        sfCircleShape_setPosition(circle, (sfVector2f) {info->character_move.x -
                    90, info->character_move.y - 90});
        test_camera(sprites->sprite, info);
        sfRenderWindow_setView(game->window, info->camera);
        sfSprite_setPosition(sprites->next->sprite, info->character_move);
        do_mines_loop(game, sprites, box, circle);
        manage_window_info(game);
        check_quest(game, info, box);
        draw_informations(game, info, informations, game_rect->next);
        do_transition(game, &shade, timer, new_game);
        sfRenderWindow_display(game->window);
    }
}
