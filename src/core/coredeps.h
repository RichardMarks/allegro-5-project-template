#ifndef COREDEPS_H
#define COREDEPS_H

#include <cstdio>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

typedef struct t_COREGLOBALS {
  ALLEGRO_TIMER* Timer;
  ALLEGRO_EVENT_QUEUE* Queue;
  ALLEGRO_DISPLAY* Display;
  ALLEGRO_BITMAP* DisplayBuffer;
  ALLEGRO_FONT* Font;
  ALLEGRO_EVENT Event;

  unsigned char KeysDown[ALLEGRO_KEY_MAX];

  unsigned int Setup;

  bool Running;
  bool Redraw;
  bool Ticked;
  bool Windowed;

  int ResWidth;
  int ResHeight;
  float WinWidth;
  float WinHeight;
  float Width;
  float Height;
  float Scale;
  float ScaleX;
  float ScaleY;
  float BufferX;
  float BufferY;
  float BufferW;
  float BufferH;

  void (*InitFunc)();
  void (*DestroyFunc)();
  void (*UpdateFunc)();
  void (*RenderFunc)();
} _COREGLOBALS;

extern _COREGLOBALS __CoreGlobals__;

extern bool core_main_loop();
extern bool core_init ();
extern void core_quit ();
extern bool core_running ();
extern bool core_update ();
extern bool core_render ();
extern void core_present ();

#endif // !COREDEPS_H
