#include <SDL.h>
#include <SDL_image.h>
#include <ErrorTracker.h>
#include <Surface.h>
namespace lp {

	Surface::Surface(): surf(NULL), error(ErrorTracker()) {}

	Surface::~Surface() {
		Close();
	}

	SDL_Surface *Surface::GetSurface()const {
		return surf;
	}

	bool Surface::Error()const {
		return error();
	}

	const char *Surface::ErrorMsg()const {
		return error.Message();
	}

	void Surface::LoadBMP(const char *file){
		surf = SDL_LoadBMP(file);
		if(surf ==NULL) {
			error.Set(true, SDL_GetError());
		}
		else {
			error.Set(false, "");
		}
	}

	void Surface::LoadImage(const char *file) {
		surf = IMG_Load(file);
		if(surf == NULL) {
			error.Set(true, IMG_GetError());
		}
		else {
			error.Set(false, "");
		}
	}

	void Surface::Close() {
		if(surf != NULL) {
			SDL_FreeSurface(surf);
			surf = NULL;
			error.Set(true, "Not initialized");
		}
	}

	
	void Surface::SetColorKey(Uint8 r, Uint8 g, Uint8 b) {
		if(!error()) {
			if(SDL_SetColorKey(surf, SDL_TRUE, 
							   SDL_MapRGB(surf->format, r, g, b)) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Surface::Blit(SDL_Rect *src_rect, SDL_Surface *dest,
					   SDL_Rect *dest_rect) {
		if(!error()) {
			if(SDL_BlitSurface(surf, src_rect, dest, dest_rect) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Surface::BlitFull(SDL_Surface *dest, SDL_Rect *dest_rect) {
		if(!error()) {
			if(SDL_BlitSurface(surf, NULL, dest, dest_rect) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Surface::BlitScaled(SDL_Rect *src_rect, SDL_Surface *dest,
							 SDL_Rect *dest_rect) {
		if(!error()) {
			if(SDL_BlitScaled(surf, src_rect, dest, dest_rect) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Surface::BlitScaledFull(SDL_Surface *dest, SDL_Rect *dest_rect) {
		if(!error()) {
			if(SDL_BlitScaled(surf, NULL, dest, dest_rect) < 0) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Surface::Optimize(SDL_PixelFormat *format, Uint32 flags) {
		if(!error()) { 
			SDL_Surface *aux = SDL_ConvertSurface(surf, format, flags);
			if(aux == NULL) {
				error.Set(true, SDL_GetError());
			}
			else {
				Close();
				surf = aux;
				error.Set(false, "");
			}
		}
	}

} //namespace
