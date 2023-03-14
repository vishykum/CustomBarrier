#ifndef CUSTOMBARRIER_H
#define CUSTOMBARRIER_H
#include <atomic>
#include <mutex>
#include <condition_variable>

/*Custom Barrier Implemetation
* The Barrier enables a user to establish a pre-defined order across all threads
*/

class CustomBarrier {
private:
    std::atomic<uint16_t> counter;
    uint16_t n_threads;
    std::condition_variable condVar;
    std::mutex mutex_;
    
public:
    CustomBarrier(uint16_t n) : counter(0), n_threads(n) {}

    //Each thread calling wait() is blocked until it has been called nthreads amount of times across all the threads
    void wait();
};

#endif