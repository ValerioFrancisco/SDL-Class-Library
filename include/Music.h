#ifndef MUSIC_H
#define MUSIC_H
#include <ErrorTracker.h>

namespace lp {
	class Music {
		public:
			Music();
			virtual ~Music();

			virtual Mix_Music* GetMusic()const;
			virtual bool Error()const;
			virtual const char *ErrorMsg()const;

			virtual void LoadMusic(const char *file);

			virtual bool Playing()const;
			virtual bool Paused()const;

			virtual void Pause();
			// plays music in the number of loops, -1 plays indefinately
			virtual void Play(int loops = -1);
			virtual void Stop();
			virtual void Resume();
			
			virtual void Close();
		private:
			Mix_Music *music;
			ErrorTracker error;
	};
} // namespace
#endif
