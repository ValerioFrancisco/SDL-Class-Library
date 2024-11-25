#ifndef INIT_H
#define INIT_H
#include "ErrorTracker.h"
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

			// Closes SDL subsystems
			virtual void Close();

			// Gets the error status
			virtual bool Error()const;

			// Gets the error message
			virtual const char *ErrorMsg()const;

		private:
			// Becomes true if there is an error in initialization
			ErrorTracker error;
	};

} // namespace
#endif // INIT_H
