
#include <cub3d.h>
#include "miniaudio.h"

int play_music_loop(ma_engine *engine, ma_sound *sound, const char *filename, int loop)
{
    ma_result result;

    result = ma_engine_init(NULL, engine);
    if (result != MA_SUCCESS)
    {
        printf("Failed to initialize audio engine\n");
        return -1;
    }
    result = ma_sound_init_from_file(engine, filename, MA_SOUND_FLAG_LOOPING, NULL, NULL, sound);
    if (result != MA_SUCCESS)
    {
        printf("Failed to load sound\n");
        ma_engine_uninit(engine);
        return -1;
    }
    result = ma_sound_start(sound);
    if (result != MA_SUCCESS)
    {
        printf("Failed to start sound\n");
        ma_sound_uninit(sound);
        ma_engine_uninit(engine);
        return -1;
    }
    return 0;
}

void stop_loop_music(ma_engine *engine, ma_sound *sound)
{
    ma_sound_uninit(sound);
    ma_engine_uninit(engine);
}
