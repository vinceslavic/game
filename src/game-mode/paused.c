#include "game.h"
#include "raylib.h"

void game_input_paused(struct Game *game) {
    if (IsKeyPressed(KEY_Q)) {
        game->state = GAME_MENU;
    } else if (IsKeyPressed(KEY_P)) {
        game->state = GAME_PLAYING;
    }
}

void game_update_paused(struct Game *game) {
}

void game_render_paused(struct Game *game) {
    DrawText(TextFormat("TIME: %lld", game->timer), 100, 100, 24, WHITE);
    DrawText("PAUSED", 100, 200, 24, WHITE);
    DrawText("P to unpause", 100, 300, 24, WHITE);
    DrawText("Q to quit", 100, 400, 24, WHITE);
}
