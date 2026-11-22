#include "game.h"
#include "raylib.h"

void game_input_menu(struct Game *game) {
    bool pressed = IsKeyPressed(KEY_SPACE);
    if (pressed) {
        game->state = GAME_PLAYING;
    }
}

void game_update_menu(struct Game *game) {
}

void game_render_menu(struct Game *game) {
    DrawText("MAIN MENU", 100, 100, 24, WHITE);
    DrawText("Hit space to start playing", 100, 200, 24, WHITE);
}
