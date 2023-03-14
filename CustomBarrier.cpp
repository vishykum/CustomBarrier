#include "CustomBarrier.h"

void CustomBarrier::wait() {
        uint16_t expected = counter;
        counter.compare_exchange_strong(expected, (expected + 1));

        if (this->counter == this->n_threads) {
            counter = 0;
            condVar.notify_all();
            return;
        }

        std::unique_lock<std::mutex> lck(mutex_);
        condVar.wait(lck);
    }