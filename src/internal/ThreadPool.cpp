#include "Thread.cpp"
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <vector>

class ThreadPool {
private:
    int numThreads;
    std::vector<Thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex taskMutex;
    std::condition_variable taskCV;
    bool stop;

public:
    ThreadPool(int numThreads) : numThreads(numThreads), stop(false) {
        for(int i = 0; i < numThreads; ++i) {
            threads.emplace_back([this]() { workerThread(); });
        }
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(taskMutex);
            stop = true;
        }
        taskCV.notify_all();

        for(int i = 0; i < numThreads; ++i) {
            threads[i].join();
        }
    }

    void addTask(const std::function<void()> &task) {
        {
            std::unique_lock<std::mutex> lock(taskMutex);
            tasks.push(task);
        }
        taskCV.notify_one();
    }

private:
    void workerThread() {
        while(true) {
            std::function<void()> task;

            {
                std::unique_lock<std::mutex> lock(taskMutex);

                taskCV.wait(lock, [this]() { return stop || !tasks.empty(); });

                if(stop && tasks.empty()) {
                    break;
                }

                if(!tasks.empty()) {
                    task = tasks.front();
                    tasks.pop();
                }
            }

            if(task) {
                task();
            }
        }
    }
};
