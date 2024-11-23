#include <SDL.h>
#include <Init.h>
namespace lp {

	Init::Init():error(true)  {
		Initialize();
	}

	Init::Init(Uint32 flags) {
		Initialize(flags);
	}

	Init::~Init() {
		Close();
	}

	void Init::Initialize(Uint32 flags) {
		if(SDL_Init(flags) < 0) error = true;
		else error = false;
	}

	void Init::Close() {
		SDL_Quit();
	}

	bool Init::Error()const {
		return error;
	}

} // namespace
