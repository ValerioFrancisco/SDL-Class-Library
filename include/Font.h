#ifndef FONT_H
#define FONT_H
#include <ErrorTracker.h>
#include <SDL_ttf.h>
namespace lp {

	class Font {
		public:
			Font();
			virtual ~Font();

			virtual TTF_Font *GetFont()const;
			virtual bool Error()const;
			virtual const char* ErrorMsg()const;

			void Create(const char *file, int size);
			void Close();

		private:
			TTF_Font *font;
			ErrorTracker error;
	};

} // namespace
#endif
