#include "core.h"

#define CORE_SETUP_WAS_CALLED_BEFORE_CORE_RUN 0xDEADBEEF

int core_run(void (*init_func)(), void (*update_func)(), void (*render_func)(),
             void (*destroy_func)()) {
  printf("core_run()\n");
  assert(init_func != NULL);
  assert(update_func != NULL);
  assert(render_func != NULL);
  assert(destroy_func != NULL);
  assert(__CoreGlobals__.Setup == CORE_SETUP_WAS_CALLED_BEFORE_CORE_RUN);

  __CoreGlobals__.InitFunc = init_func;
  __CoreGlobals__.DestroyFunc = destroy_func;
  __CoreGlobals__.UpdateFunc = update_func;
  __CoreGlobals__.RenderFunc = render_func;

  __CoreGlobals__.Running = true;

  if (!core_main_loop()) {
    return 1;
  }
  return 0;
}
