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
			virtual int GetWidth()const;
			virtual int GetHeight()const;

			// Creates Texture from a surface
			virtual void FromSurface(Renderer &ren, Surface &surf);

			// Loads directly from a file, discarding the surface
			virtual void FromFile(const char *file, Renderer& ren);

			virtual void FromFileColorKey(const char *file, Renderer &ren,
						Uint8 r = 0xFF, Uint8 g = 0xFF, Uint8 b = 0xFF);

			// Creates text texture
			virtual void FromSolidFont(Font &font, const char *text, 
									   SDL_Color color, Renderer &ren);

			// Sets the texture color modulation
			virtual void SetColorMod(Uint8 r, Uint8 g, Uint8 b);

			// Set Blend Mode
			virtual void SetBlend(SDL_BlendMode mode = SDL_BLENDMODE_BLEND);

			// Set alpha (transparency)
			virtual void SetAlpha(Uint8 alpha);

			virtual void Close();
		private:
			SDL_Texture *texture;
			ErrorTracker error;
			int width, height;

			// Prevent copy construction
			Texture(const Texture& other);
};

} // namespace
#endif
