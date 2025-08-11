#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_mixer/SDL_mixer.h>
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
		if(!SDL_Init(flags) ) {
			error.Set(true, SDL_GetError());
		}
		else {
			error.Set(false, "");
		}
	}

	void Init::InitFont() {
		if(!error()) {
			if(!TTF_Init()) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Init::InitMixer() {
		if(!error()) {
			if(!MIX_Init()) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Init::Close() {
		MIX_Quit();
		TTF_Quit();
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
