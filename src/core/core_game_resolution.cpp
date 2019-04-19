#include "core.h"

void core_game_resolution(int width, int height) {
  printf("core_game_resolution(%d, %d)\n", width, height);
  __CoreGlobals__.ResWidth = width;
  __CoreGlobals__.ResHeight = height;
}
