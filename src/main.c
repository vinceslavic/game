#include "game.h"

int main(void) {
    SetRandomSeed(0);
    InitWindow(800, 600, "game modes");
    SetTargetFPS(60);

    struct Game game = {0};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        struct GameMode *gm = &game_modes[game.state];
        gm->input(&game);
        gm->update(&game);
        gm->render(&game);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
