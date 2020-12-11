#ifndef DASYNQ_UTIL_HPP_
#define DASYNQ_UTIL_HPP_

#include "config.h"
#include <unistd.h>

namespace dasynq {

// Define pipe2, if it's not present in the sytem library. pipe2 is like pipe
// with an additional flags argument which can set file/descriptor flags
// atomically. The emulated version that we generate cannot do this atomically,
// of course.

#if DASYNQ_HAVE_PIPE2

// NOLINTNEXTLINE(misc-unused-using-decls)
using ::pipe2;

#else

inline int pipe2(int filedes[2], int flags) {
	if (pipe(filedes) == -1) {
		return -1;
	}

	if (flags & O_CLOEXEC) {
		fcntl(filedes[0], F_SETFD, FD_CLOEXEC);
		fcntl(filedes[1], F_SETFD, FD_CLOEXEC);
	}

	if (flags & O_NONBLOCK) {
		fcntl(filedes[0], F_SETFL, O_NONBLOCK);
		fcntl(filedes[1], F_SETFL, O_NONBLOCK);
	}

	return 0;
}

#endif

} // namespace dasynq

#endif /* DASYNQ_UTIL_HPP_ */
