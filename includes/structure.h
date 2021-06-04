/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** structure.h
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef STRUCTURE
#define STRUCTURE

enum menu_status {
    NEW_GAME,
    MAIN_MENU,
    SETTINGS_MENU,
    HELP_MENU,
    EXIT,
    MAIN_GAME_TOWN,
    MAIN_GAME_SHOP,
    MAIN_GAME_SWAMP,
    MAIN_GAME_MINES,
    PAUSE_MENU,
    SETTINGS_PAUSE,
    SAVE_MENU,
    INVENTORY_MENU,
};

typedef struct sfx_structure
{
    sfMusic *menu_theme;
    sfMusic *game_theme;
    sfMusic *combat_theme;
    sfSound *game_over;
    sfSound *launch_game;
    sfSound *typing_sound;
    sfSound *success_sound;
    sfSoundBuffer *launch_game_buffer;
    sfSoundBuffer *typing_sound_buffer;
    sfSoundBuffer *success_sound_buffer;
    sfSoundBuffer *game_over_buffer;
}t_sfx;

typedef struct window_structure
{
    int oldstatus;
    int status;
    unsigned int fpslimit;
    sfBool VSync;
    t_sfx sfx;
    int soundVolume;
    int musicVolume;
    sfVideoMode videoMode;
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i mousePos;
    sfVector2u windowSize;
}t_window;


typedef struct sprite_structure
{
    sfSprite *sprite;
    char *filepath;
    sfVector2f pos;
    sfVector2f scale;
    sfTexture *texture;
    struct sprite_structure *next;
    struct sprite_structure *prev;
}t_sprite;


typedef struct text_structure
{
    int name;
    sfText *text;
    char *str;
    sfVector2f pos;
    sfVector2f scale;
    const char *font_filepath;
    sfFont *font;
    struct text_structure *next;
    struct text_structure *prev;
}t_text;

typedef struct rect_structure
{
    sfRectangleShape *rectangle;
    sfVector2f pos;
    sfVector2f size;
    sfColor colorFill;
    sfColor colorOutline;
    struct rect_structure *next;
    struct rect_structure *prev;
}t_rect;

typedef struct clock_structure
{
    sfClock *fpsClock;
    int fps;
    sfClock *spriteClock;
    int spriteStatus;
    sfClock *vectorClock;
}t_clock;

typedef struct combat_structure
{
    int turn;
    sfClock *clock_turn;
    sfClock *clock;
    sfRectangleShape *white_fade;
    sfRectangleShape *box;
    sfText *attack;
    sfText *big_attack;
    sfText *guard;
    sfText *you_win;
    sfText *you_lose;
    sfText *your_turn;
    sfText *enemy_turn;
    sfRectangleShape *box_middle;
    sfSprite *floor;
    sfSprite *wall;
}t_infoCombat;

typedef struct fighter_structure
{
    sfSprite *sprite;
    sfText *name;
    int name_len;
    sfVector2f position;
    sfRectangleShape *max_health_bar;
    sfRectangleShape *health_bar;
    int max_health;
    int current_health;
    int defense;
    int attack;
    int atk_power;
    int last_move;
    int big_atk_pp;
}t_infoFighter;

typedef struct game_structure
{
    int statushistory;
    int statusMove;
    char *player_name;
    sfView *camera;
    sfImage *background_pause;
    sfVector2f character_move;
    t_infoFighter player;
    t_infoFighter enemy;
    t_infoCombat combat;
    int money;
}t_infoGame;

typedef struct sprite_sheet_structure
{
    int status;
    void (*function)(t_clock *clock, sfIntRect *spriteRect);
}t_spriteSheet;

typedef struct status_structure
{
    int status;
    void (*function)(t_window *game, t_clock *clock, t_infoGame *info);
}t_status;

#endif /* !STRUCTURE */
