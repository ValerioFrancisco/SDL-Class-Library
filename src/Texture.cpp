#include <SDL.h>
#include <Surface.h>
#include <Renderer.h>
#include <Texture.h>
#include <ErrorTracker.h>

namespace lp {

	Texture::Texture():texture(NULL), error(ErrorTracker()), width(0), 
						height(0) {}
	
	Texture::~Texture() { Close(); }

	SDL_Texture* Texture::GetTexture()const { return texture; }

	bool Texture::Error()const { return error(); }

	const char *Texture::ErrorMsg()const { return error.Message(); }

	int Texture::GetWidth()const { return width; }
	int Texture::GetHeight()const { return height; }

	void Texture::FromSurface(Renderer &ren, Surface &surf){
		if(!surf.Error() && !ren.Error()) {
			texture = SDL_CreateTextureFromSurface(ren.GetRenderer(),
												   surf.GetSurface());
			width = surf.GetSurface()->w;
			height = surf.GetSurface()->h;
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
			width = surf.GetSurface()->w;
			height = surf.GetSurface()->h;
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
			width = surf.GetSurface()->w;
			height = surf.GetSurface()->h;
			FromSurface(ren, surf);
		}
	}
	
	void Texture::SetColorMod(Uint8 r, Uint8 g, Uint8 b) {
		if(!error()) {
			if(SDL_SetTextureColorMod(texture, r, g, b) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Texture::SetBlend(SDL_BlendMode mode) {
		if(!error()) {
			if(SDL_SetTextureBlendMode(texture, mode) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Texture::SetAlpha(Uint8 alpha) {
		if(!error()) {
			if(SDL_SetTextureAlphaMod(texture , alpha) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Texture::Close() {
		if(texture != NULL) {
			SDL_DestroyTexture(texture);
			texture = NULL;
			error.Set(true, "Not Initialized");
			width = 0;
			height = 0;
		}
	}
	
} // namespace
