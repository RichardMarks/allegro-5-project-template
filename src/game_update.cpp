#include "core/core.h"
#include "game.h"

void game_update () {
  // printf("game_update()\n");

  // TODO: update game logic here

  // FIXME: use core controller interface
  if (__CoreGlobals__.KeysDown[ALLEGRO_KEY_ESCAPE]) {
    core_stop();
  }

}
