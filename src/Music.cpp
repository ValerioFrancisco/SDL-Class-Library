#include <SDL.h>
#include <SDL_mixer.h>
#include <Music.h>
#include <ErrorTracker.h>

namespace lp {

	Music::Music(): music(NULL), error(ErrorTracker()) {}

	Music::~Music() { Close(); }

	Mix_Music *Music::GetMusic()const { return music; }

	bool Music::Error()const { return error(); }

	const char *Music::ErrorMsg()const { return error.Message(); }

	bool Music::Playing()const { return Mix_PlayingMusic(); }

	bool Music::Paused()const { return Mix_PausedMusic(); }

	void Music::LoadMusic(const char *file) {
		Close();
		music = Mix_LoadMUS(file);
		if(music == NULL) error.Set(true, Mix_GetError());
		else error.Set(false, "");
	}

	void Music::Close() {
		if(music != NULL) {
			Mix_FreeMusic(music);
			music = NULL;
			error.Set(true, "Not initialized");
		}
	}

	void Music::Pause() {
		if(!Mix_PausedMusic() && Mix_PlayingMusic()) Mix_PauseMusic();
	}

	void Music::Play(int loops) {
		if(!Mix_PlayingMusic()) Mix_PlayMusic(music, loops);
	}

	void Music::Stop() {
		if(Mix_PlayingMusic()) Mix_HaltMusic();
	}

	void Music::Resume() {
		if(Mix_PlayingMusic() && Mix_PausedMusic()) Mix_ResumeMusic();
	}

} //namespace
