#ifndef TEXTURE_H
#define TEXTURE_H
#include <ErrorTracker.h>

// Encapsulates Hardware accelerated Textures
namespace lp {

	class Texture {
		public:
			Texture();
			virtual ~Texture();

			virtual SDL_Texture *GetTexture()const;
			virtual bool Error()const;
			virtual const char *ErrorMsg()const;

			// Creates Texture from a surface
			virtual void FromSurface(Renderer &ren, Surface &surf);

			// Loads directly from a file, discarding the surface
			virtual void FromFile(const char *file, Renderer& ren);

			virtual void FromFileColorKey(const char *file, Renderer &ren,
						Uint8 r = 0xFF, Uint8 g = 0xFF, Uint8 b = 0xFF);

			virtual void Close();
		private:
			SDL_Texture *texture;
			ErrorTracker error;

			// Prevent copy construction
			Texture(const Texture& other);
};

} // namespace
#endif
