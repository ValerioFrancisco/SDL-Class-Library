#ifndef SOUNDFX_H
#define SOUNDFX_H
#include <ErrorTracker.h>

namespace lp {

    // Loads and plays simple sound effects
	class Soundfx {
		public:
			Soundfx();
			virtual ~Soundfx();

            // Gets pointer
			virtual Mix_Chunk *GetChunk()const;

			// Gets error status and message
			virtual bool Error()const;
			virtual const char *ErrorMsg()const;

            // Loads from file
			virtual void LoadWAV(const char *file);

            // Plays sound effect
			virtual void Play(int channel = -1, int loops = 0);

            // Cleans up memory
			virtual void Close();

		private:
			Mix_Chunk * chunk;
			ErrorTracker error;
	};

} // namespace
#endif
