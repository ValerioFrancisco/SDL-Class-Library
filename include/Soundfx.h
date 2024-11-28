#ifndef SOUNDFX_H
#define SOUNDFX_H
#include <ErrorTracker.h>

namespace lp {

	class Soundfx {
		public:
			Soundfx();
			virtual ~Soundfx();

			virtual Mix_Chunk *GetChunk()const;
			virtual bool Error()const;
			virtual const char *ErrorMsg()const;

			virtual void LoadWAV(const char *file);

			virtual void Play(int channel = -1, int loops = 0);

			virtual void Close();

		private:
			Mix_Chunk * chunk;
			ErrorTracker error;
	};

} // namespace
#endif
