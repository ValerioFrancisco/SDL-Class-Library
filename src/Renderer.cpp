#include <SDL.h>
#include <Window.h>
#include <ErrorTracker.h>
#include <Window.h>
#include <Renderer.h>

namespace lp {

	Renderer::Renderer(): ren(NULL), error(ErrorTracker()) {}

	Renderer::~Renderer() { Close(); }

	SDL_Renderer *Renderer::GetRenderer()const { return ren; }

	bool Renderer::Error()const { return error(); }

	const char *Renderer::ErrorMsg()const { return error.Message(); }

	void Renderer::Create(Window &win, int index, Uint32 flags) {
		ren = SDL_CreateRenderer(win.GetWindow(), index, flags);
		if(ren == NULL) error.Set(true, SDL_GetError());
		else error.Set(false, "");
	}

	void Renderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
		if(!error()) {
			if(SDL_SetRenderDrawColor(ren, r, g, b, a) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Renderer::Copy( SDL_Texture *texture, const SDL_Rect *src,
						 const SDL_Rect *dest) {
		if(!error()) {
			if(SDL_RenderCopy(ren, texture, src, dest) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Renderer::Present() {
		if(!error()) {
			SDL_RenderPresent(ren);
		}
	}

	void Renderer::Close() {
		if(ren != NULL) {
			SDL_DestroyRenderer(ren);
			ren = NULL;
			error.Set(true, "Not initialized");
		}
	}
} // namespace
