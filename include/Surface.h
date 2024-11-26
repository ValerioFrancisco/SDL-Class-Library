#ifndef SURFACE_H
#define SURFACE_H
#include <ErrorTracker.h>
namespace lp {

	// Encapsulates SDL surfaces and related operations
	// takes care of memory management
	// requires SDL.h
	class Surface {
		public:

			// Creates object, but it does not initialize
			// sets error to true, other functions init the surface
			Surface();
			virtual ~Surface();

			virtual SDL_Surface *GetSurface()const;
			virtual bool Error()const;
			virtual const char *ErrorMsg()const;

			// Loads a bitmap onto the surface
			virtual void LoadBMP(const char *file);
			// Loads an SDL_image image type
			virtual void LoadImage(const char *file);

			// Optimizes surface to the desired format
			// deallocates the old surface after
			virtual void Optimize(SDL_PixelFormat *format, 
								  Uint32 flags = 0);

			// Blits the source rectangle fom this surface to the
			// destination surface rectangle 
			virtual void Blit(SDL_Rect *src_rect, SDL_Surface  *dest,
							  SDL_Rect *dest_rect = NULL);

			// Blits the full loaded Surface
			virtual void BlitFull(SDL_Surface *dest, 
								  SDL_Rect *dest_rect = NULL); 
			
			// Blits a scaled optimized Surface
			virtual void BlitScaled(SDL_Rect * src_rect, SDL_Surface *dest,
									SDL_Rect *dest_rect = NULL);
			virtual void BlitScaledFull(SDL_Surface *dest,
										SDL_Rect *dest_rect);

			// Frees memory if allocated
			virtual void Close();
		private:
			SDL_Surface *surf;
			ErrorTracker error;
	};

} // namespace
#endif
