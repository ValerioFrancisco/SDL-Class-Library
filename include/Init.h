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

			// Initializes according to the flags passed, these are:
			// SDL_INIT_TIMER: timer subsystem
			// SDL_INIT_AUDIO: audio subsystem
			// SDL_INIT_VIDEO: video subsystem; automatically initializes the
			// events subsystem
			// SDL_INIT_JOYSTICK: joystick subsystem; automatically initializes
			// the events subsystem
			// SDL_INIT_HAPTIC: haptic (force feedback) subsystem
			// SDL_INIT_GAMECONTROLLER: controller subsystem; automatically
			// initializes the joystick subsystem
			// SDL_INIT_EVENTS: events subsystem
			// SDL_INIT_EVERYTHING: all of the above subsystems
			// SDL_INIT_NOPARACHUTE: compatibility; this flag is ignored
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
			void InitMixer();

			// Closes SDL subsystems
			virtual void Close();

			// Gets the error status
			virtual bool Error()const;

			// Gets the error message
			virtual const char *ErrorMsg()const;

		private:
			// Becomes true if there is an error in initialization
			ErrorTracker error;

			// disallows copy constructor
			Init(const Init &other);
	};

} // namespace
#endif // INIT_H
