#include <SDL.h>
#include <Surface.h>
namespace lp {

	Surface::Surface(): surf(NULL), error(true) {}

	Surface::~Surface() {
		Close();
	}

	SDL_Surface *Surface::GetSurface()const {
		return surf;
	}

	bool Surface::Error()const {
		return error;
	}

	void Surface::LoadBMP(const char *file){
		surf = SDL_LoadBMP(file);
		if(surf ==NULL) error = true;
		else error = false;
	}

	void Surface::Close() {
		if(surf != NULL) {
			SDL_FreeSurface(surf);
			surf = NULL;
		}
	}

	void Surface::Blit(SDL_Rect *src_rect, SDL_Surface *dest,
					   SDL_Rect *dest_rect) {
		if(SDL_BlitSurface(surf, src_rect, dest, dest_rect) < 0) {
			error = true;
		}
	}

} //namespace
