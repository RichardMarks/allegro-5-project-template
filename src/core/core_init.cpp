#include "core.h"

bool core_init() {
  printf("core_init()\n");

  if (!al_init()) {
    printf("core_init() Error: al_init failed.\n");
    return false;
  }

  if (!al_install_keyboard()) {
    printf("core_init() Error: al_install_keyboard failed.\n");
    return false;
  }

  if (!al_install_mouse()) {
    printf("core_init() Error: al_install_mouse failed.\n");
    return false;
  }

  if (!al_install_audio()) {
    printf("core_init() Error: al_install_audio failed.\n");
    return false;
  }

  __CoreGlobals__.Timer = al_create_timer(1.0 / 30.0);
  if (!__CoreGlobals__.Timer) {
    printf("core_init() Error: al_create_timer failed.\n");
    return false;
  }

  __CoreGlobals__.Queue = al_create_event_queue();
  if (!__CoreGlobals__.Queue) {
    printf("core_init() Error: al_create_event_queue failed.\n");
    return 1;
  }

  int windowWidth = __CoreGlobals__.WinWidth;
  int windowHeight = __CoreGlobals__.WinHeight;

  if (__CoreGlobals__.Windowed) {
    al_set_new_display_flags(ALLEGRO_WINDOWED);
  } else {
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
  }

  __CoreGlobals__.Display = al_create_display(windowWidth, windowHeight);
  if (!__CoreGlobals__.Display) {
    printf("core_init() Error: al_create_display failed. (%d x %d) [%s]\n",
           windowWidth, windowHeight,
           __CoreGlobals__.Windowed ? "Windowed" : "Fullscreen");
    return false;
  }

  if (!__CoreGlobals__.Windowed) {
    __CoreGlobals__.WinWidth = al_get_display_width(__CoreGlobals__.Display);
    __CoreGlobals__.WinHeight = al_get_display_height(__CoreGlobals__.Display);
  }

  __CoreGlobals__.DisplayBuffer =
      al_create_bitmap(__CoreGlobals__.ResWidth, __CoreGlobals__.ResHeight);
  if (!__CoreGlobals__.DisplayBuffer) {
    printf("core_init() Error: al_create_bitmap failed. (%d x %d)\n",
           __CoreGlobals__.ResWidth, __CoreGlobals__.ResHeight);
    return false;
  }

  if (!al_init_font_addon()) {
    printf("core_init() Error: al_init_font_addon failed.\n");
    return false;
  }

  if (!al_init_ttf_addon()) {
    printf("core_init() Error: al_init_ttf_addon failed.\n");
    return false;
  }

  if (!al_init_image_addon()) {
    printf("core_init() Error: al_init_image_addon failed.\n");
    return false;
  }

  if (!al_init_acodec_addon()) {
    printf("core_init() Error: al_init_acodec_addon failed.\n");
    return false;
  }

  if (!al_reserve_samples(1)) {
    printf("core_init() Error: al_reserve_samples failed.\n");
    return false;
  }

  __CoreGlobals__.Font = al_create_builtin_font();
  if (!__CoreGlobals__.Font) {
    printf("core_init() Error: al_create_builtin_font failed.\n");
    return false;
  }

  __CoreGlobals__.Width = __CoreGlobals__.ResWidth;
  __CoreGlobals__.Height = __CoreGlobals__.ResHeight;

  float aspectRatio =
      (float)__CoreGlobals__.ResWidth / (float)__CoreGlobals__.ResHeight;
  __CoreGlobals__.BufferW = (float)__CoreGlobals__.WinHeight * aspectRatio;
  __CoreGlobals__.BufferH = __CoreGlobals__.WinHeight;
  __CoreGlobals__.BufferX =
      (__CoreGlobals__.WinWidth - __CoreGlobals__.BufferW) * 0.5f;
  __CoreGlobals__.BufferY =
      (__CoreGlobals__.WinHeight - __CoreGlobals__.BufferH) * 0.5f;
  __CoreGlobals__.ScaleX = __CoreGlobals__.BufferW / __CoreGlobals__.WinWidth;
  __CoreGlobals__.ScaleY = __CoreGlobals__.BufferH / __CoreGlobals__.WinHeight;
  __CoreGlobals__.Scale = __CoreGlobals__.ScaleX < __CoreGlobals__.ScaleY
                              ? __CoreGlobals__.ScaleX
                              : __CoreGlobals__.ScaleY; // FIXME: this is wrong

  // printf("BufferW: %f\n"
  //        "BufferH: %f\n"
  //        "BufferX: %f\n"
  //        "BufferY: %f\n"
  //        "Scale: %f\n"
  //        "ResWidth: %f\n"
  //        "ResHeight: %f\n"
  //        "WinWidth: %f\n"
  //        "WinHeight: %f\n"
  //        "Width: %f\n"
  //        "Height: %f\n",
  //        (float)__CoreGlobals__.BufferW, (float)__CoreGlobals__.BufferH,
  //        (float)__CoreGlobals__.BufferX, (float)__CoreGlobals__.BufferY,
  //        (float)__CoreGlobals__.Scale, (float)__CoreGlobals__.ResWidth,
  //        (float)__CoreGlobals__.ResHeight, (float)__CoreGlobals__.WinWidth,
  //        (float)__CoreGlobals__.WinHeight, (float)__CoreGlobals__.Width,
  //        (float)__CoreGlobals__.Height);

  al_register_event_source(__CoreGlobals__.Queue,
                           al_get_keyboard_event_source());
  al_register_event_source(__CoreGlobals__.Queue, al_get_mouse_event_source());
  al_register_event_source(__CoreGlobals__.Queue, al_get_display_event_source(
                                                      __CoreGlobals__.Display));
  al_register_event_source(__CoreGlobals__.Queue,
                           al_get_timer_event_source(__CoreGlobals__.Timer));

  memset(__CoreGlobals__.KeysDown, 0, sizeof(__CoreGlobals__.KeysDown));

  // clear controllers
  // memset(&p1, 0, sizeof(p1));

  __CoreGlobals__.Running = true;

  return true;
}
