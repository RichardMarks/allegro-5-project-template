#include "core.h"

void core_setup () {
  printf("core_setup()\n");

  memset(&__CoreGlobals__, 0, sizeof(__CoreGlobals__));

  __CoreGlobals__.ResWidth = CORE_DEFAULT_WINDOW_WIDTH;
  __CoreGlobals__.ResHeight = CORE_DEFAULT_WINDOW_HEIGHT;
  __CoreGlobals__.Windowed = true;
  __CoreGlobals__.WinWidth = CORE_DEFAULT_WINDOW_WIDTH;
  __CoreGlobals__.WinHeight = CORE_DEFAULT_WINDOW_HEIGHT;

  __CoreGlobals__.Setup = 0xDEADBEEF;
}
