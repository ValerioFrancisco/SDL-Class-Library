#ifndef ERRORTRACKER_H
#define ERRORTRACKER_H
#include <string>
namespace lp {

	// Auxiliar class to keep track of errors in SDL code
	// requires <string>
	class ErrorTracker {
		public:
			ErrorTracker();
			ErrorTracker(bool status, const char *error_msg);
			virtual ~ErrorTracker();

			virtual bool GetStatus()const;
			virtual bool operator()()const;
			virtual const char *Message()const;

			virtual void Set(bool status, const char *msg);

		private:
			bool error;
			std::string error_msg;
	};
}
#endif
