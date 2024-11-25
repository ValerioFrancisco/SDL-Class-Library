#include <SDL.h>
#include <Window.h>
#include <ErrorTracker.h>
namespace lp {

	Window::Window(): win(NULL), surf(NULL), error(ErrorTracker()) {}

	Window::Window(const char *title,
				   int width,
				   int height, 
				   int xposition,
				   int yposition,
				   Uint32 flags): win(NULL),
							      surf(NULL),
							      error(ErrorTracker()){
		Create(title, width, height, xposition, yposition, flags);
	}

	Window::~Window() {
		Close();
	}

	SDL_Window *Window::GetWindow()const {
		return win;
	}

	SDL_Surface *Window::GetSurface()const {
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
						int xposition,
						int yposition,
						Uint32 flags) {
		win = SDL_CreateWindow(title, xposition, yposition,
						    width, height, flags);
		if(win == NULL) error.Set(true, SDL_GetError());
		else {
			surf = SDL_GetWindowSurface(win);
			if(surf == NULL) {
				error.Set(true, SDL_GetError());
			}
			error.Set(false, "");
		}
	}

	void Window::Update() {
		if(!error()) {
			if(SDL_UpdateWindowSurface(win) < 0) 
				error.Set(true, SDL_GetError());
		}
	}

} // namespace
