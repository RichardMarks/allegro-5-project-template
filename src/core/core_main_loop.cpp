#include "core.h"

_COREGLOBALS __CoreGlobals__;

bool core_main_loop() {
  printf("core_main_loop()\n");

  if (!core_init()) {
    return false;
  }
  __CoreGlobals__.InitFunc();

  al_start_timer(__CoreGlobals__.Timer);
  __CoreGlobals__.Redraw = false;

  while (__CoreGlobals__.Running) {
    if (core_update()) {
      __CoreGlobals__.UpdateFunc();
    }
    if (core_render()) {
      __CoreGlobals__.RenderFunc();
    }
    core_present();
  }
  __CoreGlobals__.DestroyFunc();
  core_quit();
  return true;
}
