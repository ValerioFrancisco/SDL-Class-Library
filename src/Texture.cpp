#include <SDL.h>
#include <Surface.h>
#include <Renderer.h>
#include <Texture.h>
#include <ErrorTracker.h>

namespace lp {

	Texture::Texture():texture(NULL), error(ErrorTracker()) {}
	
	Texture::~Texture() { Close(); }

	SDL_Texture* Texture::GetTexture()const { return texture; }

	bool Texture::Error()const { return error(); }

	const char *Texture::ErrorMsg()const { return error.Message(); }

	void Texture::FromSurface(Renderer &ren, Surface &surf){
		if(!surf.Error() && !ren.Error()) {
			texture = SDL_CreateTextureFromSurface(ren.GetRenderer(),
												   surf.GetSurface());
			if(texture == NULL) {
				error.Set(true, SDL_GetError());
			}
			else {
				error.Set(false, "");
			}
		}
	}

	void Texture::FromFile(const char *file, Renderer &ren) {
		Surface surf;
		surf.LoadImage(file);
		if(surf.Error()) {
			error.Set(true, surf.ErrorMsg());
		}
		else {
			FromSurface(ren, surf);
		}
	}

	void Texture::FromFileColorKey(const char *file, Renderer &ren,
					Uint8 r, Uint8 g, Uint8 b) {
		Surface surf;
		surf.LoadImage(file);
		surf.SetColorKey(r, g, b);
		if(surf.Error()) {
			error.Set(true, surf.ErrorMsg());
		}
		else {
			FromSurface(ren, surf);
		}
	}

	void Texture::Close() {
		if(texture != NULL) {
			SDL_DestroyTexture(texture);
			texture = NULL;
			error.Set(true, "Not Initialized");
		}
	}
	
} // namespace
