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

extern struct GameMode game_modes[GAME_STATE__COUNT];

#endif//GAME_H
