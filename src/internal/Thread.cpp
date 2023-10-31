#include <functional>
#include <thread>

class Thread {
private:
    std::function<void()> func;
    std::thread tObj;

public:
    Thread(std::function<void()> tFunc) : func(tFunc) {}

    void start() {
        tObj = std::thread(func);
    }

    void join() {
        if(tObj.joinable()) {
            tObj.join();
        }
    }
};
