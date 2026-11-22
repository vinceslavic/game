#include "game.h"

void game_input_playing(struct Game *game) {
    bool pressed = IsKeyPressed(KEY_P);
    if (pressed) {
        game->state = GAME_PAUSED;
    }
}

void game_update_playing(struct Game *game) {
    game->timer = time(0);
}

void game_render_playing(struct Game *game) {
    DrawText(TextFormat("TIME: %lld", game->timer), 100, 100, 24, WHITE);
}
