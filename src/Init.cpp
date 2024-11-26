#include <SDL.h>
#include <SDL_image.h>
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
			if(!IMG_Init(flags) & flags) {
				error.Set(true, IMG_GetError());
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
