#ifndef FONT_H
#define FONT_H
#include <ErrorTracker.h>
#include <SDL_ttf.h>
namespace lp {

	class Font {
		public:
			Font();
			virtual ~Font();

            // Gets a pointer to the font
			virtual TTF_Font *GetFont()const;

			// Gets Error status and message if so
			virtual bool Error()const;
			virtual const char* ErrorMsg()const;

            // Creates font from a file, with specified size
			void Create(const char *file, int size);
			void Close();

		private:
			TTF_Font *font;
			ErrorTracker error;
	};

} // namespace
#endif
