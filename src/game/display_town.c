/*
** EPITECH PROJECT, 2021
** display_game
** File description:
** display the game
*/

#include "rpg.h"
#include "game.h"
#include "chained_list.h"
#include "lib.h"
#include "structure.h"
#include <stdlib.h>

char **remove_jump_line_at_end(char **buffer)
{
    if (!buffer)
        return NULL;
    for (int i = 0; buffer[i]; i += 1)
        if (buffer[i][my_strlen(buffer[i]) - 1] == '\n')
            buffer[i][my_strlen(buffer[i]) - 1] = '\0';
    return buffer;
}

void change_texture(t_sprite **sprites, char *config_file, int state,
    t_infoGame *info)
{
    sfIntRect area = {0};
    char **content_file = NULL;

    if (info->statusMove != DOWN && info->statusMove != UP && info->statusMove
        != LEFT && info->statusMove != RIGHT)
        return;
    if (state >= 3)
        state = 1;
    content_file = fopen_getline(content_file, config_file);
    if (content_file == NULL)
        return;
    content_file = remove_jump_line_at_end(content_file);
    area = find_area(content_file[info->statusMove], state);
    if (!(*sprites))
        (*sprites) = create_sprite(content_file[0], info->character_move,
            (sfVector2f) {0.4, 0.4});
    (*sprites)->texture = sfTexture_createFromFile(content_file[0], &area);
    sfSprite_setTexture((*sprites)->sprite, (*sprites)->texture, 1);
    for (int i = 0; content_file[i]; i += 1)
        free(content_file[i]);
    free(content_file);
}

static void init_combat_struct(t_infoGame *info)
{
    char *config_path = get_line_file("assets/save/player_info.txt", 2);
    char *texture_path = get_line_file(config_path, 1);
    sfTexture *player_texture = sfTexture_createFromFile(texture_path, NULL);
    sfIntRect player_rect = {48, 0, 47, 47};

    free(config_path);
    free(texture_path);
    sfSprite_setTexture(info->player.sprite, player_texture, 1);
    sfSprite_setTextureRect(info->player.sprite, player_rect);
    info->player.position = (sfVector2f) {300, 300};
    info->enemy.position = (sfVector2f) {1400, 300};
    sfSprite_setScale(info->player.sprite, (sfVector2f) {5, 5});
    info->player_name = get_line_file("assets/save/player_info.txt", 1);
    sfText_setString(info->player.name, info->player_name);
    info->player.name_len = my_strlen(info->player_name);
    sfText_setString(info->enemy.name, "Dark Knight");
    info->enemy.name_len = my_strlen(sfText_getString(info->enemy.name));
}

static void init_box_and_sprites(t_rect **box, t_sprite **sprites,
    char **config_character, t_infoGame *info)
{
    char **config_rectangle = NULL;

    config_rectangle = fopen_getline(config_rectangle,
            "assets/config_file/town.txt");
    if (config_rectangle == NULL)
        return;
    config_rectangle = remove_jump_line_at_end(config_rectangle);
    create_box_from_config(&config_rectangle[1], box);
    *sprites = create_sprite(config_rectangle[0],
                            (sfVector2f) {0, 0}, (sfVector2f) {0.5, 0.5});
    info->statusMove = DOWN;
    change_texture(&(*sprites)->next, config_character[1], 1, info);
}

static char **init_game_window(char **config_character, t_infoGame *info,
    t_window *game)
{
    config_character = fopen_getline(config_character,
            "assets/save/player_info.txt");
    if (*config_character == NULL)
        return NULL;
    config_character = remove_jump_line_at_end(config_character);
    sfView_setSize(info->camera, (sfVector2f){1920 / 4, 1080 / 4});
    sfRenderWindow_setView(game->window, info->camera);
    return config_character;
}

static void set_in_loop(t_window *game, t_sprite *sprites, t_rect *box,
                        t_infoGame *info)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfView_setCenter(info->camera, (sfVector2f) {info->character_move.x +
            10, info->character_move.y + 23.5});
    test_camera(sprites->sprite, info);
    sfRenderWindow_setView(game->window, info->camera);
    sfSprite_setPosition(sprites->next->sprite, info->character_move);
    draw_sprite(&game->window, sprites);
}

static void set_new_music(t_window *game)
{
    if (sfMusic_getStatus(game->sfx.game_theme) == sfStopped) {
        sfMusic_play(game->sfx.game_theme);
    }
    if (sfMusic_getStatus(game->sfx.combat_theme) == sfPlaying) {
        sfMusic_stop(game->sfx.combat_theme);
        sfMusic_play(game->sfx.game_theme);
    }
}

void draw_informations(t_window *game, t_infoGame *info,
    t_text *informations, t_rect *rectangle)
{
    const char *str = NULL;
    sfVector2f pos = sfView_getCenter(info->camera);

    sfRectangleShape_setPosition(rectangle->rectangle, (sfVector2f)
        {pos.x + 132, pos.y - 134});
    sfRectangleShape_setOutlineThickness(rectangle->rectangle, 0.5);
    sfRenderWindow_drawRectangleShape(game->window, rectangle->rectangle, NULL);
    for (; informations; informations = informations->next) {
        sfText_setPosition(informations->text, (sfVector2f)
            {pos.x + 133, pos.y - 132});
        str = sfText_getString(informations->text);
        if (info->statushistory == 0 && str[0] == '1')
            sfRenderWindow_drawText(game->window,
                    informations->text, NULL);
        else if (info->statushistory == 1 && str[0] == '2')
            sfRenderWindow_drawText(game->window,
                    informations->text, NULL);
        else if (info->statushistory == 2 && str[0] == '3')
            sfRenderWindow_drawText(game->window,
                    informations->text, NULL);
        else if (info->statushistory == 3 && str[0] == '4')
            sfRenderWindow_drawText(game->window,
                    informations->text, NULL);
        else if (info->statushistory == 4 && str[0] == '5')
            sfRenderWindow_drawText(game->window,
                    informations->text, NULL);
        else if (info->statushistory == 5 && str[0] == '6')
            sfRenderWindow_drawText(game->window,
                    informations->text, NULL);
    }
}

void end_game(t_window *game, t_infoGame *info)
{
    sfView_reset(info->camera, (sfFloatRect) {0, 0, 1920, 1031});
    sfRenderWindow_setView(game->window, info->camera);
    game->status = MAIN_MENU;
    info->statushistory = 0;
    info->character_move.x = 410;
    info->character_move.y = 380;
    info->player.max_health = 50;
    info->player.defense = 30;
    sfMusic_stop(game->sfx.game_theme);
    sfMusic_play(game->sfx.menu_theme);
    info->money = 0;
}

void display_game(t_window *game, t_clock *clock, t_infoGame *info)
{
    int event = 0;
    sfUint8 shade = 255;
    char **config_character = NULL;
    t_rect *box = NULL;
    t_rect *game_rect = create_rect_game();
    t_sprite *sprites = NULL;
    sfClock *timer = sfClock_create();
    t_text *informations = create_info_game_text();

    config_character = init_game_window(config_character, info, game);
    init_box_and_sprites(&box, &sprites, config_character, info);
    init_combat_struct(info);
    set_new_music(game);
    create_town_game_sprite(&sprites);
    while (sfRenderWindow_isOpen(game->window)) {
        event = poll_event_game(game, info, clock, box);
        if (event == 1)
            return;
        else if (event == 2)
            change_texture(&sprites->next, config_character[1],
                clock->spriteStatus - 1, info);
        if (is_in_color_rect(sprites->next, box, sfBlack))
            talk_to_people(game, sprites, info, box);
        if (info->statushistory == 6) {
            end_game(game, info);
            return;
        }
        manage_window_info(game);
        set_in_loop(game, sprites, box, info);
        draw_informations(game, info, informations, game_rect->next);
        do_transition(game, &shade, timer, game_rect);
        sfRenderWindow_display(game->window);
    }
}
