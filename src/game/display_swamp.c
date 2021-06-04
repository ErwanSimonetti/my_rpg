/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** display_swamp.c
*/

#include "structure.h"
#include "rpg.h"
#include "chained_list.h"
#include "lib.h"
#include "game.h"

static const char *STEPS = "assets/font/Steps.ttf";

static void init_box_and_sprites(t_rect **box, t_sprite **sprites,
    char **config_character, t_infoGame *info)
{
    char **config_rectangle = NULL;

    config_rectangle = fopen_getline(config_rectangle,
        "assets/config_file/swamp.txt");
    if (config_rectangle == NULL)
        return;
    config_rectangle = remove_jump_line_at_end(config_rectangle);
    create_box_from_config(&config_rectangle[1], box);
    *sprites = create_sprite(config_rectangle[0],
            (sfVector2f) {0, 0}, (sfVector2f) {0.5, 0.5});
    change_texture(&(*sprites)->next, config_character[1], 1, info);
    *sprites = add_sprite_inlist(*sprites, create_sprite(
            "assets/img/zombie.png", (sfVector2f){194, 430}, (sfVector2f){0.45,
            0.45}), len_list_sprite(*sprites));
    *sprites = add_sprite_inlist(*sprites, create_sprite(
            "assets/img/zombie.png", (sfVector2f){363, 410}, (sfVector2f){0.45,
            0.45}), len_list_sprite(*sprites));
    *sprites = add_sprite_inlist(*sprites, create_sprite(
            "assets/img/darkknight.png",
            (sfVector2f){334, 165}, (sfVector2f){0.6, 0.6}), len_list_sprite(
            *sprites));
    *box = add_rectangle_inlist(*box, create_rect((sfVector2f){194, 430},
            (sfVector2f){20, 30}, sfYellow, sfYellow), len_list_rect(*box));
    *box = add_rectangle_inlist(*box, create_rect((sfVector2f){363, 410},
            (sfVector2f){20, 30}, sfYellow, sfYellow), len_list_rect(*box));
    *box = add_rectangle_inlist(*box, create_rect((sfVector2f){334, 165},
            (sfVector2f){20, 30}, sfWhite, sfWhite), len_list_rect(*box));
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
        info->enemy.sprite = create_sprite("assets/img/darkknight.png",
            (sfVector2f){1000, 300}, (sfVector2f){7, 7})->sprite;
        info->enemy.name = create_text("Dark Knight", (sfVector2f){0, 0},
            (sfVector2f){1, 1}, STEPS)->text;
        sfText_setColor(info->enemy.name, sfColor_fromRGB(255, 84, 84));
        info->enemy.defense = 55;
        if (display_combat(game, info) == 1) {
            delete_enemy(sprites->next, box, sfWhite);
            sfView_setSize(info->camera, (sfVector2f){1920 / 4, 1080 / 4});
        }
    }
}

static char **init_swamp_window(char **config_character, t_infoGame *info)
{
    config_character = fopen_getline(config_character,
        "assets/save/player_info.txt");
    if (*config_character == NULL)
        return NULL;
    config_character = remove_jump_line_at_end(config_character);
    sfView_setSize(info->camera, (sfVector2f){1920 / 4, 1080 / 4});
    return config_character;
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
            && info->statushistory == 4) {
                sfSound_play(game->sfx.success_sound);
                info->statushistory = 5;
                return;
            }
    }
}

static void do_swamp_loop(t_window *game, t_sprite *sprites, t_infoGame *info,
    t_rect *box)
{
    sfView_setCenter(info->camera, (sfVector2f) {info->character_move.x +
                10, info->character_move.y + 23.5});
    sfSprite_setPosition(sprites->next->sprite, info->character_move);
    test_camera(sprites->sprite, info);
    sfRenderWindow_setView(game->window, info->camera);
    sfRenderWindow_clear(game->window, sfBlack);
    draw_sprite(&game->window, sprites);
}

static void draw_particles(t_window *game, t_rect *particles)
{
    sfVector2f pos = {0, 0};

    for (t_rect *tmp = particles; tmp; tmp = tmp->next) {
        pos = sfRectangleShape_getPosition(tmp->rectangle);
        if (pos.y >= 1080)
            sfRectangleShape_move(tmp->rectangle, (sfVector2f) {0, -1080});
        sfRectangleShape_move(tmp->rectangle, (sfVector2f) {0, 4});
        sfRenderWindow_drawRectangleShape(game->window, tmp->rectangle, NULL);
    }
}

void display_swamp(t_window *game, t_clock *clock, t_infoGame *info)
{
    int event = 0;
    char **config_character = NULL;
    sfUint8 shade = 255;
    t_sprite *sprites = NULL;
    sfClock *timer = sfClock_create();
    t_text *informations = create_info_game_text();
    t_rect *box = NULL;
    t_rect *particles = creat_rect_particles();
    t_rect *game_rect = create_rect_game();

    config_character = init_swamp_window(config_character, info);
    init_box_and_sprites(&box, &sprites, config_character, info);
    while (sfRenderWindow_isOpen(game->window)) {
        event = poll_event_game(game, info, clock, box);
        if (event == 1)
            return;
        else if (event == 2)
            change_texture(&sprites->next, config_character[1],
                clock->spriteStatus - 1, info);
        manage_combat(game, info, sprites, box);
        do_swamp_loop(game, sprites, info, box);
        manage_window_info(game);
        draw_particles(game, particles);
        check_quest(game, info, box);
        draw_informations(game, info, informations, game_rect->next);
        do_transition(game, &shade, timer, game_rect);
        sfRenderWindow_display(game->window);
    }
}
