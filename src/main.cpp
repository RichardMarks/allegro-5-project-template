#include "core/core.h"
#include "game.h"

int main(int argc, char *argv[]) {
  core_setup();
  core_game_resolution(320, 240);
  // core_window(CORE_FULLSCREEN_WINDOW);
  return core_run(&game_init, &game_update, &game_render, &game_destroy);
}
