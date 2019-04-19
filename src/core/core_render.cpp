#include "core.h"

bool core_render() {
  // printf("core_render()\n");

  if (__CoreGlobals__.Redraw && al_is_event_queue_empty(__CoreGlobals__.Queue)) {
    __CoreGlobals__.Redraw = false;
    al_set_target_bitmap(__CoreGlobals__.DisplayBuffer);
    al_clear_to_color(al_map_rgb(0, 0, 0)); // FIXME: should use a global background color

    return true;
  }
  return false;
}
