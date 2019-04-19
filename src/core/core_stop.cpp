#include "core.h"

void core_stop() {
  printf("core_stop()\n");
  __CoreGlobals__.Running = false;
  __CoreGlobals__.Ticked = false;
  __CoreGlobals__.Redraw = false;
}
