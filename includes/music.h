#ifndef MUSIC_H
# define MUSIC_H

#include "miniaudio.h"

#define MINIAUDIO_IMPLEMENTATION

int play_music_loop(ma_engine *engine, ma_sound *sound, const char *filename, int loop);
void stop_loop_music(ma_engine *engine, ma_sound *sound);

#endif