#ifndef CORE_H
#define CORE_H

#include "coredeps.h"

#define CORE_FULLSCREEN_WINDOW 1
#define CORE_WINDOW 2

#define CORE_DEFAULT_WINDOW_MODE CORE_WINDOW
#define CORE_DEFAULT_WINDOW_WIDTH 640
#define CORE_DEFAULT_WINDOW_HEIGHT 480

extern void core_setup();
extern void core_game_resolution(int width, int height);
extern void core_window(int flags);
extern int core_run(void (*init_func)(), void (*update_func)(),
                    void (*render_func)(), void (*destroy_func)());
extern void core_stop();

#endif // !CORE_H
