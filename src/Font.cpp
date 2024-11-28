#include <SDL.h>
#include <SDL_ttf.h>
#include <Font.h>
#include <ErrorTracker.h>

namespace lp {

	Font::Font(): font(NULL), error(ErrorTracker()) {}

	Font::~Font() { Close(); }

	TTF_Font *Font::GetFont()const { return font; }

	bool Font::Error()const { return error(); }

	const char *Font::ErrorMsg()const { return error.Message(); }

	void Font::Create(const char *file, int size) {
		if(!error()) Close();
		font = TTF_OpenFont(file, size);
		if(font == NULL) {
			error.Set(true, TTF_GetError());
		}
		else {
			error.Set(false, "");
		}
	}

	void Font::Close() {
		if(!error() || font != NULL) {
			TTF_CloseFont(font);
			font = NULL;
			error.Set(true, "Not Initialized");
		}
	}

} // namespace
