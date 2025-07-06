#include <string>
#include <ErrorTracker.h>
namespace lp {

	ErrorTracker::ErrorTracker(): error(true), error_msg("Not initialized") {}

	ErrorTracker::ErrorTracker(bool status, const char* error_msg):
		error(status), error_msg(error_msg) {}

	ErrorTracker::~ErrorTracker() {}

	bool ErrorTracker::GetStatus()const { return error; }

	bool ErrorTracker::operator()()const { return error; }

	const char *ErrorTracker::Message()const {
	    return error_msg.c_str();
    }

	void ErrorTracker::Set(bool status, const char *msg) {
		error = status;
		error_msg = msg;
	}
}
