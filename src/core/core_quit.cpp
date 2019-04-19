#include "core.h"

void core_quit () {
  printf("core_quit()\n");

  if (__CoreGlobals__.Font) {
    al_destroy_font(__CoreGlobals__.Font);
    __CoreGlobals__.Font = NULL;
  }

  if (__CoreGlobals__.DisplayBuffer) {
    al_destroy_bitmap(__CoreGlobals__.DisplayBuffer);
    __CoreGlobals__.DisplayBuffer = NULL;
  }

  if (__CoreGlobals__.Display) {
    al_destroy_display(__CoreGlobals__.Display);
    __CoreGlobals__.Display = NULL;
  }

  if (__CoreGlobals__.Timer) {
    al_destroy_timer(__CoreGlobals__.Timer);
    __CoreGlobals__.Timer = NULL;
  }

  if (__CoreGlobals__.Queue) {
    al_destroy_event_queue(__CoreGlobals__.Queue);
    __CoreGlobals__.Queue = NULL;
  }
}
