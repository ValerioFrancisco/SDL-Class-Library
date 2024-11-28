#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <ErrorTracker.h>
#include <Init.h>
namespace lp {


	Init::Init():error(ErrorTracker()) {
		Initialize();
	}

	Init::Init(Uint32 flags) {
		Initialize(flags);
	}

	Init::~Init() {
		Close();
	}

	void Init::Initialize(Uint32 flags) {
		if(SDL_Init(flags) < 0) {
			error.Set(true, SDL_GetError());
		}
		else {
			error.Set(false, "");
		}
	}

	void Init::InitImage(int flags) {
		if(!error()) {
			if(!(IMG_Init(flags) & flags)) {
				error.Set(true, IMG_GetError());
			}
		}
	}

	void Init::InitFont() {
		if(!error()) {
			if(TTF_Init() == -1) {
				error.Set(true, TTF_GetError());
			}
		}
	}

	void Init::InitMixer(int frequency, Uint32 format, int channels,
						 int chunksize) {
		if(!error()) {
			if(Mix_OpenAudio(frequency, format, channels, chunksize) < 0) {
				error.Set(true, Mix_GetError());
			}
		}
	}

	void Init::Close() {
		IMG_Quit();
		SDL_Quit();
		error.Set(true, "Not initialized");
	}

	bool Init::Error()const {
		return error();
	}

	const char *Init::ErrorMsg()const {
		return error.Message();
	}


} // namespace
