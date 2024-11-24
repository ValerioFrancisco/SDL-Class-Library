#ifndef SURFACE_H
#define SURFACE_H
namespace lp {

	// Encapsulates SDL surfaces and related operations
	// takes care of memory management
	class Surface {
		public:

			// Creates object, but it does not initialize
			// sets error to true, other functions init the surface
			Surface();
			virtual ~Surface();

			virtual SDL_Surface *GetSurface()const;
			virtual bool Error()const;

			// loads a bitmap onto the surface
			virtual void LoadBMP(const char *file);

			virtual void Blit(SDL_Rect *src_rect, SDL_Surface  *dest,
							  SDL_Rect *dest_rect = NULL);
			// frees memory if allocated
			virtual void Close();
		private:
			SDL_Surface *surf;
			bool error;
	};

} // namespace
#endif
