#include "core.h"

void core_window(int flags) {
  printf("core_window(%d)\n", flags);

  __CoreGlobals__.Windowed = flags == CORE_FULLSCREEN_WINDOW ? false : true;
}
