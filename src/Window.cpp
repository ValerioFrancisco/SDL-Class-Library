#include <SDL3/SDL.h>
#include <Window.h>
#include <ErrorTracker.h>
namespace lp {

	Window::Window(): win(NULL), error(ErrorTracker()) {}

	Window::Window(const char *title,
				   int width,
				   int height,
				   SDL_WindowFlags flags): win(NULL),
							      error(ErrorTracker()){
		Create(title, width, height, flags);
	}

	Window::~Window() {
		Close();
	}

	SDL_Window *Window::GetWindow()const {
		return win;
	}

	SDL_Surface *Window::GetSurface()const {
	    SDL_Surface *surf = NULL;
	    if(!error()) {
            surf = SDL_GetWindowSurface(win);
	    }
	    return surf;
	}

	bool Window::Error()const {
		return error();
	}

	const char *Window::ErrorMsg()const {
		return error.Message();
	}

	void Window::Close() {
		if(win != NULL) {
			SDL_DestroyWindow(win);
			win = NULL;
			error.Set(true, "Not Initialized");
		}
	}

	void Window::Create(const char *title,
				   		int width,
						int height,
						SDL_WindowFlags flags) {
		if(!error() || win != NULL) Close();
		win = SDL_CreateWindow(title, width, height, flags);
		if(win == NULL) error.Set(true, SDL_GetError());
		else error.Set(false, "");
	}

	void Window::Update() {
		if(!error()) {
			if(SDL_UpdateWindowSurface(win) < 0)
				error.Set(true, SDL_GetError());
		}
	}

} // namespace
