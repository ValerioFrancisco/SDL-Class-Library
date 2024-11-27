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

			virtual void FromSurface(Renderer &ren, Surface &surf);

			virtual void Close();
		private:
			SDL_Texture *texture;
			ErrorTracker error;
};

} // namespace
#endif
