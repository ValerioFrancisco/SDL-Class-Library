#ifndef INIT_H
#define INIT_H

namespace lp {

	// Takes care of all basic SDL Initializations
	class Init
	{
		public:

			// Initializes video only
			Init();

			// Does all the cleanup
			virtual ~Init();

			// Initializes SDL with only video by default
			virtual void Initialize(Uint32 flags = SDL_INIT_VIDEO);

			// Closes SDL subsystems
			virtual void Close();

			// Gets the error status
			virtual bool Error()const;

		private:
			// Becomes true if there is an error in initialization
			bool error;
	};

} // namespace
#endif // INIT_H
