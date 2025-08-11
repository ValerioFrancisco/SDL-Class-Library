#include <SDL.h>
#include <Window.h>
#include <ErrorTracker.h>
#include <Window.h>
#include <Renderer.h>
#include <Texture.h>
namespace lp {

	Renderer::Renderer(): ren(NULL), error(ErrorTracker()) {}

	Renderer::~Renderer() { Close(); }

	SDL_Renderer *Renderer::GetRenderer()const { return ren; }

	bool Renderer::Error()const { return error(); }

	const char *Renderer::ErrorMsg()const { return error.Message(); }

	void Renderer::Create(Window &win, const char *name) {
		if(!error()) { Close(); }
		ren = SDL_CreateRenderer(win.GetWindow(), name);
		if(ren == NULL) error.Set(true, SDL_GetError());
		else error.Set(false, "");
	}

	void Renderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
		if(!error()) {
			if(!SDL_SetRenderDrawColor(ren, r, g, b, a)) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Renderer::Copy(const Texture &texture, const SDL_FRect *src,
						 const SDL_FRect *dest) {
		if(!error()) {
			if(!SDL_RenderTexture(ren, texture.GetTexture(), src, dest)) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Renderer::CopyRotated(const Texture &txtr, 
						  const SDL_FRect *src,
						  const SDL_FRect *dest,
						  const double angle,
						  const SDL_FPoint *center,
						  const SDL_FlipMode flip) {
		if(!error()) {
			if(!SDL_RenderTextureRotated(ren, txtr.GetTexture(),
										 src, dest, angle, center, flip)) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Renderer::DrawPoint(float x, float y) {
		if(!error()) {
			if(!SDL_RenderPoint(ren, x,y)) {
				error.Set(true, SDL_GetError());
			}
		}
	}
	
	void Renderer::DrawLine(float x1, float y1, float x2, float y2) {
		if(!error()) {
			if(!SDL_RenderLine(ren, x1, y1, x2, y2)) {
				error.Set(true, SDL_GetError());
			}
		}
	}	
	void Renderer::DrawRect(const SDL_FRect &rect) {
		if(!error()) {
			if(SDL_RenderRect(ren, &rect) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Renderer::FillRect(const SDL_FRect &rect) {
		if(!error()) {
			if(SDL_RenderFillRect(ren, &rect) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Renderer::SetViewport(const SDL_Rect &vp) {
		if(!error()) {
			if(SDL_SetRenderViewport(ren, &vp) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Renderer::ResetViewport() {
		if(!error()) {
			if(SDL_SetRenderViewport(ren, NULL) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	SDL_Rect Renderer::GetViewport()const {
		SDL_Rect res;
		SDL_GetRenderViewport(ren, &res);
		return res;
	}

	void Renderer::Clear() {
		if(!error()) {
			if(SDL_RenderClear(ren) < 0) error.Set(true, SDL_GetError());
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
