#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <ErrorTracker.h>
#include <Mixer.h>

namespace lp {

    Mixer::Mixer(SDL_AudioDeviceID devid, const SDL_AudioSpec *spec ) {
       mix = MIX_CreateMixerDevice(devid, spec);
       if(!mix) {
        error.Set(true, SDL_GetError());
       }
       else error.Set(false, "");
    }

    Mixer::~Mixer() {
        MIX_DestroyMixer(mix);
        mix = NULL;
    }

    bool Mixer::Error()const {
        return error();
    }

    const char* Mixer::ErrorMsg()const {
        return error.Message();
    }

    MIX_Mixer* Mixer::GetMixer() {
        return mix;
    }
}