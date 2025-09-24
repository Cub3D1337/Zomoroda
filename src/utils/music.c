
#include <cub3d.h>
// #include "miniaudio.h"

// int play_music_loop(ma_engine *engine, ma_sound *sound, const char *filename, int loop)
// {
//     ma_result result;

//     result = ma_engine_init(NULL, engine);
//     if (result != MA_SUCCESS)
//     {
//         printf("Failed to initialize audio engine\n");
//         return -1;
//     }
//     result = ma_sound_init_from_file(engine, filename, MA_SOUND_FLAG_LOOPING, NULL, NULL, sound);
//     if (result != MA_SUCCESS)
//     {
//         printf("Failed to load sound\n");
//         ma_engine_uninit(engine);
//         return -1;
//     }
//     result = ma_sound_start(sound);
//     if (result != MA_SUCCESS)
//     {
//         printf("Failed to start sound\n");
//         ma_sound_uninit(sound);
//         ma_engine_uninit(engine);
//         return -1;
//     }
//     return 0;
// }

// void stop_loop_music(ma_engine *engine, ma_sound *sound)
// {
//     ma_sound_uninit(sound);
//     ma_engine_uninit(engine);
// }



static SDL_AudioDeviceID device = 0;
static Uint8 *audio_buf = NULL;
static Uint32 audio_len = 0;
static int loop_enabled = 0;
static SDL_AudioSpec wav_spec;
static Uint8 *audio_pos = NULL;

void audio_callback(void *userdata, Uint8 *stream, int len) {
    if (audio_len == 0) {
        if (loop_enabled) {
            // restart from beginning
            audio_pos = (Uint8 *)userdata;
            audio_len = *(Uint32 *)(userdata + sizeof(Uint8 *));
        } else {
            memset(stream, 0, len); // silence if no loop
            return;
        }
    }

    int to_copy = (len > (int)audio_len ? audio_len : len);
    SDL_memcpy(stream, audio_pos, to_copy);

    audio_pos += to_copy;
    audio_len -= to_copy;

    if (to_copy < len) {
        // fill rest with silence if file ended
        SDL_memset(stream + to_copy, 0, len - to_copy);
    }
}

int play_music_loop(const char *filename, int loop) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL_Init error: %s\n", SDL_GetError());
        return -1;
    }

    if (SDL_LoadWAV(filename, &wav_spec, &audio_buf, &audio_len) == NULL) {
        printf("Failed to load WAV: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    loop_enabled = loop;
    audio_pos = audio_buf;

    wav_spec.callback = audio_callback;
    wav_spec.userdata = audio_buf; // pass original buffer for restart

    device = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
    if (device == 0) {
        printf("Failed to open audio: %s\n", SDL_GetError());
        SDL_FreeWAV(audio_buf);
        SDL_Quit();
        return -1;
    }

    SDL_PauseAudioDevice(device, 0); // start playing
    return 0;
}

void stop_loop_music() {
    if (device != 0) {
        SDL_CloseAudioDevice(device);
        device = 0;
    }
    if (audio_buf) {
        SDL_FreeWAV(audio_buf);
        audio_buf = NULL;
    }
    SDL_Quit();
}
