#include "core.h"

void core_present() {
  // printf("core_present()\n");

  al_set_target_backbuffer(__CoreGlobals__.Display);
  al_clear_to_color(
      al_map_rgb(0x30, 0x30, 0x30)); // FIXME: should use global color
  al_draw_scaled_bitmap(__CoreGlobals__.DisplayBuffer, 0, 0,
                        __CoreGlobals__.ResWidth, __CoreGlobals__.ResHeight,
                        __CoreGlobals__.BufferX, __CoreGlobals__.BufferY,
                        __CoreGlobals__.BufferW, __CoreGlobals__.BufferH, 0);
  al_flip_display();
}
