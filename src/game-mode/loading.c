#include "game.h"

void game_input_loading(struct Game *game) {
}

void game_update_loading(struct Game *game) {
    static int frames = 0;
    if (++frames >= 240) {
        frames = 0;
        game->state = GAME_MENU;
    }
}

void game_render_loading(struct Game *game) {
    static int frames = 0;
    ++frames;
    static const char label[] = "L O A D I N G . . .";
    enum { label_count = _Countof(label) };
    int frames_per_cycle = 3;
    int current_count = frames / frames_per_cycle;
    if (current_count > label_count) {
        current_count = label_count;
    }
    if (frames > (frames_per_cycle * label_count + 10)) {
        frames = 0;
    }
    char buf[label_count+1];
    __builtin_memcpy(buf, label, current_count);
    buf[current_count] = 0;
    DrawText(buf, 100, 100, 24, WHITE);
}
