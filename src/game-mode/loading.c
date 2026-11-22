#include "game.h"

void game_input_loading(struct Game *game) {
}

void game_update_loading(struct Game *game) {
    static int frames = 0;
    // fake loading for 240 frames
    if (++frames >= 240) {
        frames = 0;
        game->state = GAME_MENU;
    }
}

void game_render_loading(struct Game *game) {
    static int frames = 0;
    ++frames;

    // label animation
    static const char label[] = "L O A D I N G . . .";
    enum { label_count = _Countof(label) };

    // add next character every 3 frames
    int frames_per_cycle = 3;
    int current_count = frames / frames_per_cycle;
    if (current_count > label_count) {
        current_count = label_count;
    }

    // reset animation after 10 frames
    if (frames > (frames_per_cycle * label_count + 10)) {
        frames = 0;
    }

    // copy current count characters from label into a buffer
    char buf[label_count+1];
    __builtin_memcpy(buf, label, current_count);
    buf[current_count] = 0;

    // draw text from buffer
    DrawText(buf, 100, 100, 24, WHITE);
}
