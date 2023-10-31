#include <mutex>

class Mutex {
private:
    std::mutex mutex;

public:
    void lock() {
        mutex.lock();
    }

    void unlock() {
        mutex.unlock();
    }

    bool try_lock() {
        return mutex.try_lock();
    }
};