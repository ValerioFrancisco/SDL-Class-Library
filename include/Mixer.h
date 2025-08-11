#ifndef MIXER_H
#define MIXER_H
#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <ErrorTracker.h>
namespace lp {
    
    // encapsulates a mixer for audio output
    class Mixer {
        public:
            Mixer(SDL_AudioDeviceID devid = SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK,
                  const SDL_AudioSpec *spec = NULL);
            ~Mixer();

            bool Error()const;
            const char* ErrorMsg()const;
            MIX_Mixer* GetMixer();

        private:
            MIX_Mixer* mix;
            ErrorTracker error;
    };
}
#endif