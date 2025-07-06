#ifndef MUSIC_H
#define MUSIC_H
#include <ErrorTracker.h>

namespace lp {

    // Loads music, with play/pause/stop operations
	class Music {
		public:
			Music();
			virtual ~Music();

            // Gets Pointer
			virtual Mix_Music* GetMusic()const;

			// Gets error status and message if any
			virtual bool Error()const;
			virtual const char *ErrorMsg()const;

            // Loads music from file
			virtual void LoadMusic(const char *file);

			// status getters
			virtual bool Playing()const;
			virtual bool Paused()const;

			// Pauses music
			virtual void Pause();

			// plays music in the number of loops, -1 plays indefinately
			virtual void Play(int loops = -1);

			// Stops the music
			virtual void Stop();

			// Resumes music if paused
			virtual void Resume();

			// Clears memory
			virtual void Close();
		private:
			Mix_Music *music;
			ErrorTracker error;
	};
} // namespace
#endif
