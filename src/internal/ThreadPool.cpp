#ifndef THREAD_POOL
#define THREAD_POOL
#include "Thread.cpp"
#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <vector>

class ThreadPool { //Thread Pool Dinamica
private:
    std::vector<Thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex taskMutex;
    std::condition_variable taskCV;
    std::atomic<bool> stop;

public:
    ThreadPool() : stop(false) {
        int numThreads = 1; // Inizia con un thread
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

        for(Thread &thread : threads) {
            thread.join();
        }
    }

    void addTask(const std::function<void()> &task) {
        {
            std::unique_lock<std::mutex> lock(taskMutex);
            tasks.push(task);
        }
        taskCV.notify_one();
    }

    void addThread() {
        std::unique_lock<std::mutex> lock(taskMutex);
        threads.emplace_back([this]() { workerThread(); });
    }

    void removeThread() {
        if(threads.size() > 1) {
            std::unique_lock<std::mutex> lock(taskMutex);
            tasks.push(nullptr); // Aggiungi un segnaposto per la rimozione del thread
            taskCV.notify_one();
        }
    }

private:
    void workerThread() {
        while(!stop) {
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
            } else {
                // Se la task è nullptr, il thread deve essere rimosso
                break;
            }
        }
    }
};
#endif