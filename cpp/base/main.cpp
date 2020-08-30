//
// Created by lhmily on 2020/1/20.
//

#include "mutex.h"
#include <iostream>
#include <vector>

using namespace lhmily;
using namespace std;

Mutex mutex;
long count = 0;

void mutextRun() {
    mutex.lock();
    cout << count++ << endl();
    mutex.unlock();
}


int main(int argc, char *argv[]) {

    vector<*pthread_t> pthreads;
    for (int i = 0; i < 20; ++i) {
        pthread_t ptid;
         pthread_create()
        pthreads.push_back(ptid);

    }


    return 0;
}
