#ifndef INIT_H
#define INIT_H
#include <ErrorTracker.h>
namespace lp {

	// Takes care of all basic SDL Initializations and closes
	// SDL when going out of scope
	class Init
	{
		public:

			// Initializes video only
			Init();

			// Initializes according to the flags passed
			Init(Uint32 flags);

			// Does all the cleanup
			virtual ~Init();

			// Initializes SDL with only video by default
			virtual void Initialize(Uint32 flags = SDL_INIT_VIDEO);

			// Initialize Image loading
			// IMG_INIT_JPG
			// IMG_INIT_PNG
			// IMG_INIT_TIF
			virtual void InitImage(int flags);

			// Initialize Fonts
			virtual void InitFont();

			// Initialize SDL_mixer for sound.
			void InitMixer(int frequency = 44100, 
						   Uint32 format = MIX_DEFAULT_FORMAT,
						   int channels = 2,
						   int chunksize = 2048);

			// Closes SDL subsystems
			virtual void Close();

			// Gets the error status
			virtual bool Error()const;

			// Gets the error message
			virtual const char *ErrorMsg()const;

		private:
			// Becomes true if there is an error in initialization
			ErrorTracker error;

			Init(const Init &other);
	};

} // namespace
#endif // INIT_H
