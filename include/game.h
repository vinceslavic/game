#ifndef GAME_H
#define GAME_H

#include <time.h>
#include "raylib.h"

enum GameState {
    GAME_LOADING,
    GAME_MENU,
    GAME_PLAYING,
    GAME_PAUSED,
    GAME_STATE__COUNT,
};

struct Game {
    enum GameState state;
    time_t timer;
};

typedef void (*InputHandler)(struct Game *game);
typedef void (*UpdateHandler)(struct Game *game);
typedef void (*RenderHandler)(struct Game *game);

struct GameMode {
    InputHandler input;
    UpdateHandler update;
    RenderHandler render;
};

void game_input_loading(struct Game *game);
void game_update_loading(struct Game *game);
void game_render_loading(struct Game *game);

void game_input_menu(struct Game *game);
void game_update_menu(struct Game *game);
void game_render_menu(struct Game *game);

void game_input_playing(struct Game *game);
void game_update_playing(struct Game *game);
void game_render_playing(struct Game *game);

void game_input_paused(struct Game *game);
void game_update_paused(struct Game *game);
void game_render_paused(struct Game *game);

extern struct GameMode game_modes[GAME_STATE__COUNT];

#endif//GAME_H
