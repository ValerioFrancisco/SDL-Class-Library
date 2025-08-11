#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <ErrorTracker.h>
#include <Surface.h>
#include <Font.h>
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
		if(!error()) Close();
		surf = SDL_LoadBMP(file);
		if(surf ==NULL) {
			error.Set(true, SDL_GetError());
		}
		else {
			error.Set(false, "");
		}
	}

	void Surface::LoadImage(const char *file) {
		if(!error()) Close();
		surf = IMG_Load(file);
		if(surf == NULL) {
			error.Set(true, SDL_GetError());
		}
		else {
			error.Set(false, "");
		}
	}

	void Surface::LoadSolidFont(Font &font, const char *text, 
								SDL_Color color, size_t length) {
		if(!error()) Close();
		surf = TTF_RenderText_Solid(font.GetFont(), text, length, color);
		if(surf == NULL) error.Set(true, SDL_GetError());
		else error.Set(false, "");
	}

	void Surface::Close() {
		if(surf != NULL) {
			SDL_DestroySurface(surf);
			surf = NULL;
			error.Set(true, "Not initialized");
		}
	}

	
	void Surface::SetColorKey(Uint8 r, Uint8 g, Uint8 b) {
		if(!error()) {
			if(!SDL_SetSurfaceColorKey(surf, true, 
							   SDL_MapSurfaceRGB(surf, r, g, b))) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Surface::Blit(SDL_Rect *src_rect, Surface &dest,
					   SDL_Rect *dest_rect) {
		if(!error()) {
			if(!SDL_BlitSurface(surf, src_rect, dest.GetSurface(), dest_rect)) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Surface::BlitFull(Surface &dest, SDL_Rect *dest_rect) {
		if(!error()) {
			if(!SDL_BlitSurface(surf, NULL, dest.GetSurface(), dest_rect)) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Surface::BlitScaled(SDL_Rect *src_rect, Surface &dest,
							 SDL_Rect *dest_rect, SDL_ScaleMode mode) {
		if(!error()) {
			if(!SDL_BlitSurfaceScaled(surf, src_rect, dest.GetSurface(),
									  dest_rect, mode)) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Surface::BlitScaledFull(Surface &dest, SDL_Rect *dest_rect,
								 SDL_ScaleMode mode) {
		if(!error()) {
			if(!SDL_BlitSurfaceScaled(surf, NULL, dest.GetSurface(),
									  dest_rect, mode)) {
				error.Set(true, SDL_GetError());
			}
		}
	}

	void Surface::Optimize(SDL_PixelFormat format) {
		if(!error()) { 
			SDL_Surface *aux = SDL_ConvertSurface(surf, format);
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
