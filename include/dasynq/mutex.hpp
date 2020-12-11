#ifndef DASYNQ_MUTEX_HPP_
#define DASYNQ_MUTEX_HPP_

#include <mutex>

namespace dasynq {

// A "null" mutex, for which locking / unlocking actually does nothing.
class null_mutex {
public:
	void lock() {}
	void unlock() {}
	void try_lock() {}

private:
	DASYNQ_EMPTY_BODY;
};

} // namespace dasynq

#endif /* DASYNQ_MUTEX_HPP_ */
