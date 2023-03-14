#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include "CustomBarrier.h"

/*A simple program to verify that the barrier implementation is correct
* If the implementation is correct, all the Befores should be printed before the Afters
*/



std::mutex mtx;
CustomBarrier barrier(5);

void print(int n) {
    mtx.lock();
    std::cout << "Before " << n << std::endl;
    mtx.unlock();

    barrier.wait();

    mtx.lock();
    std::cout << "After" << std::endl;
    mtx.unlock();

}

int main() {
    int nthreads = 5;
    std::thread threads[nthreads];

    for(int i = 0; i < nthreads; i++) {
        threads[i] = std::thread(print, i);
    }

    for(int i = 0; i < nthreads; i++) {
        threads[i].join();
    }
    std::cout << std::endl;

    return 0;
}