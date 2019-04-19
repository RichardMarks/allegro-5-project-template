#include "core.h"

bool core_update() {
  // printf("core_update()\n");

  al_wait_for_event(__CoreGlobals__.Queue, &__CoreGlobals__.Event);

  __CoreGlobals__.Ticked = false;

  switch (__CoreGlobals__.Event.type) {
  case ALLEGRO_EVENT_TIMER: {
    __CoreGlobals__.Ticked = true;
    __CoreGlobals__.Redraw = true;

    // update_controller(p1, key);

    // clear key buffer
    for (int i = 0; i < ALLEGRO_KEY_MAX; i += 1) {
      __CoreGlobals__.KeysDown[i] &= 1;
    }
  } break;

  case ALLEGRO_EVENT_MOUSE_AXES:
    // mouseX = (__CoreGlobals__.Event.mouse.x - bufferX) * 1 / scale;
    // mouseY = (__CoreGlobals__.Event.mouse.y - bufferY) * 1 / scale;
    break;

  case ALLEGRO_EVENT_KEY_DOWN: {
    __CoreGlobals__.KeysDown[__CoreGlobals__.Event.keyboard.keycode] = 1 | 2;
  } break;

  case ALLEGRO_EVENT_KEY_UP: {
    __CoreGlobals__.KeysDown[__CoreGlobals__.Event.keyboard.keycode] &= 2;
  } break;

  case ALLEGRO_EVENT_DISPLAY_CLOSE:
    core_stop();
    break;
  }

  return __CoreGlobals__.Ticked;
}
