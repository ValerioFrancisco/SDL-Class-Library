#ifndef SURFACE_H
#define SURFACE_H
#include <SDL_ttf.h>
#include <ErrorTracker.h>
namespace lp {

	// Forward declaration;
	class Font;

	// Encapsulates SDL surfaces and related operations
	// takes care of memory management
	// requires SDL.h
	class Surface {
		public:

			// Creates object, but it does not initialize
			// sets error to true, other functions init the surface
			Surface();
			virtual ~Surface();

            // Gets the pointer to the surface
			virtual SDL_Surface *GetSurface()const;
			// Get Error Status
			virtual bool Error()const;
			// Returns the message if there is an error
			virtual const char *ErrorMsg()const;

			// Loads a bitmap onto the surface
			virtual void LoadBMP(const char *file);
			// Loads an SDL_image image type
			virtual void LoadImage(const char *file);

			// Loads a solid Font
			// TODO: add more font related rendering methods
			virtual void LoadSolidFont(Font &font, const char *text,
									   SDL_Color color, size_t length = 0);

			// Optimizes surface to the desired format
			// deallocates the old surface after
			virtual void Optimize(SDL_PixelFormat format);

			// Sets the transparent pixel
			virtual void SetColorKey(Uint8 r, Uint8 g, Uint8 b);

			// Blits the source rectangle fom this surface to the
			// destination surface rectangle
			virtual void Blit(SDL_Rect *src_rect, Surface  &dest,
							  SDL_Rect *dest_rect = NULL);

			// Blits the full loaded Surface
			virtual void BlitFull(Surface &dest,
								  SDL_Rect *dest_rect = NULL);

			// Blits a scaled optimized Surface
			virtual void BlitScaled(SDL_Rect * src_rect, Surface &dest,
									SDL_Rect *dest_rect = NULL,
									SDL_ScaleMode mode = SDL_SCALEMODE_PIXELART);

			virtual void BlitScaledFull(Surface &dest,
										SDL_Rect *dest_rect,
										SDL_ScaleMode mode = SDL_SCALEMODE_PIXELART);

			// Frees memory if allocated
			virtual void Close();
		private:
			SDL_Surface *surf;
			ErrorTracker error;

			// Prevent copy construction
			Surface(const Surface& other);
	};

} // namespace
#endif
