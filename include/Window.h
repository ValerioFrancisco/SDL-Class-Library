#ifndef WINDOW_H
#define WINDOW_H
#include <ErrorTracker.h>

namespace lp {

	// Wraps an SDL window and takes care of its destruction
	class Window {
		public:
			// Default constructor, ATTN: does not create the window
			Window();

			// Creates the window
			Window(const char *title,
				   int width,
				   int height, 
				   int xposition = SDL_WINDOWPOS_UNDEFINED,
				   int yposition = SDL_WINDOWPOS_UNDEFINED,
				   Uint32 flags = SDL_WINDOW_SHOWN);

			// Cleans up pointers
			virtual ~Window();

			// Access to the pointers
			virtual SDL_Window *GetWindow()const;
			virtual SDL_Surface *GetSurface()const;

			// Gets error status
			virtual bool Error()const;
			virtual const char *ErrorMsg()const;

			// Tries to create a window and establishes its surface
			// Called by the element constructor
			virtual void Create(const char *title,
								int width,
								int height, 
								int xposition = SDL_WINDOWPOS_UNDEFINED,
								int yposition = SDL_WINDOWPOS_UNDEFINED,
								Uint32 flags = SDL_WINDOW_SHOWN);

			// frees the window memory
			virtual void Close();

			// Updates window
			virtual void Update();

		private:
			SDL_Window *win;
			SDL_Surface *surf;
			ErrorTracker error;
	};

} // namespace
#endif
