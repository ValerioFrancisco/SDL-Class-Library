#include <SDL.h>
#include <Window.h>
namespace lp {

	Window::Window(): win(NULL), surf(NULL), error(true) {}

	Window::Window(const char *title,
				   int width,
				   int height, 
				   int xposition,
				   int yposition,
				   Uint32 flags): win(NULL),
							      surf(NULL),
							      error(true){
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
		return error;
	}

	void Window::Close() {
		if(win != NULL) SDL_DestroyWindow(win);
	}

	void Window::Create(const char *title,
				   		int width,
						int height, 
						int xposition,
						int yposition,
						Uint32 flags) {
		if(SDL_CreateWindow(title, xposition, yposition,
						    width, height, flags) == NULL) error = true;
		else {
			error = false;
			surf = SDL_GetWindowSurface(win);
		}
	}

} // namespace
