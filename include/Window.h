#ifndef WINDOW_H
#define WINDOW_H
#include <ErrorTracker.h>

namespace lp {

	// Wraps an SDL window and takes care of its destruction
	class Window {
		public:
			// Default constructor, ATTN: does not create the window,
			// use the Create() method in order to do so.
			Window();

			// Creates the window
			Window(const char *title,
				   int width,
				   int height,
				   SDL_WindowFlags flags = 0);

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
								SDL_WindowFlags flags = 0);

			// frees the window memory
			virtual void Close();

			// Updates window
			virtual void Update();

		private:
			SDL_Window *win;
			ErrorTracker error;

			// Prevent Copy construction
			Window(const Window &other);
	};

} // namespace
#endif
