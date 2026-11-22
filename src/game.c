#include "game.h"

extern void game_input_loading(struct Game *game);
extern void game_update_loading(struct Game *game);
extern void game_render_loading(struct Game *game);

extern void game_input_menu(struct Game *game);
extern void game_update_menu(struct Game *game);
extern void game_render_menu(struct Game *game);

extern void game_input_playing(struct Game *game);
extern void game_update_playing(struct Game *game);
extern void game_render_playing(struct Game *game);

extern void game_input_paused(struct Game *game);
extern void game_update_paused(struct Game *game);
extern void game_render_paused(struct Game *game);

struct GameMode game_modes[GAME_STATE__COUNT] = {
    [GAME_LOADING] = {
        .input = &game_input_loading,
        .update = &game_update_loading,
        .render = &game_render_loading,
    },
    [GAME_MENU] = {
        .input = &game_input_menu,
        .update = &game_update_menu,
        .render = &game_render_menu,
    },
    [GAME_PLAYING] = {
        .input = &game_input_playing,
        .update = &game_update_playing,
        .render = &game_render_playing,
    },
    [GAME_PAUSED] = {
        .input = &game_input_paused,
        .update = &game_update_paused,
        .render = &game_render_paused,
    },
};
