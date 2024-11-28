#include <SDL_mixer.h>
#include <Soundfx.h>
#include <ErrorTracker.h>

namespace lp {
	Soundfx::Soundfx(): chunk(NULL), error(ErrorTracker()) {}

	Soundfx::~Soundfx() { Close(); }

	Mix_Chunk *Soundfx::GetChunk()const { return chunk; }

	bool Soundfx::Error()const { return error(); }

	const char *Soundfx::ErrorMsg()const { return error.Message(); }

	void Soundfx::LoadWAV(const char *file) {
		Close();
		chunk = Mix_LoadWAV(file);
		if(chunk == NULL) error.Set(true, Mix_GetError());
		else error.Set(false, "");
	}

	void Soundfx::Play(int channel, int loops) {
		if(!error()) {
			if(Mix_PlayChannel(channel, chunk, loops) < 0) {
				error.Set(true, Mix_GetError());
			}
		}
	}

	void Soundfx::Close() {
		if(chunk != NULL) {
			Mix_FreeChunk(chunk);
			chunk = NULL;
			error.Set(true, "Not initialized");
		}
	}
		
} // namespace
