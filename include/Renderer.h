#ifndef RENDERER_H
#define RENDERER_H
#include <Window.h>
#include <ErrorTracker.h>

namespace lp {

	// Encapsulates SDL_Renderer operations
	class Renderer {
		public:
			Renderer();
			virtual ~Renderer();

            // Returnsd a pointer to the renderer
			virtual SDL_Renderer *GetRenderer()const;
			// Gets Error status
			virtual bool Error()const;
			// Gets Message in case of error
			virtual const char *ErrorMsg()const;

			// Creates a renderer to the specified window, index is
			// the driver index, flags can be OR'd together:
			// SDL_RENDERER_SOFTWARE
			// SDL_RENDERER_ACCELERATED
			// SDL_RENDERER_PRESENTVSYNC
			// SDL_RENDERER_TARGETTEXTURE
			virtual void Create(Window &win,
							    int index = -1,
								Uint32 flags = SDL_RENDERER_ACCELERATED);


			// Sets the primary draw color with RGB plus alpha channel
			virtual void SetDrawColor(Uint8 r, Uint8 g,
									  Uint8 b, Uint8 a = 0xFF);

			// Copies the rect from src to destination on renderer surface
			// NULL copies the whole texture to the whole destination
			virtual void Copy(SDL_Texture *texture, const SDL_Rect *src= NULL,
					  const SDL_Rect *dest = NULL);

			// Same as above, but with extra parameters, angle of rotation
			// around a center point (NULL for center of texture) and flip
			// that can be:
			// SDL_FLIP_NONE
			// SDL_FLIP_HORIZONTAL
			// SDL_FLIP_VERTICAL
			virtual void CopyEx(SDL_Texture *txtr,
								const SDL_Rect *src,
								const SDL_Rect *dest,
								const double angle,
								const SDL_Point *center = NULL,
								const SDL_RendererFlip flip = SDL_FLIP_NONE);

			// Renders a point
			virtual void DrawPoint(int x, int y);
			// Draws a line
			virtual void DrawLine(int x1, int y1, int x2, int y2);
			// Draws a Rectangle
			virtual void DrawRect(const SDL_Rect &rect);
			// Draws a filled rectangle
			virtual void FillRect(const SDL_Rect &rect);

            // Sets the rendering viewport to the specified rectangle
			virtual void SetViewport(const SDL_Rect& vp);
			// Resets the viewport to be the whole window
			virtual void ResetViewport();
			// returns the viewport rectangle
			virtual SDL_Rect GetViewport()const;

            // Clears the screen to the default color used by
            // the SetDrawColor() Method.
			virtual void Clear();

			// Presents all rendering on the window.
			virtual void Present();

            // Clears all used memory
			virtual void Close();

		private:
			SDL_Renderer *ren;
			ErrorTracker error;

			// Prevent copy construction
			Renderer(const Renderer &other);
	};

} // namespace
#endif
