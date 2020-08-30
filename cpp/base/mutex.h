//
// Created by lhmily on 2020/1/20.
//

#ifndef LHMILY_MUTEX_H
#define LHMILY_MUTEX_H

#include <boost/noncopyable.hpp>
#include <pthread/pthread.h>

namespace lhmily {
    class Mutex : boost::noncopyable {
    public:

        Mutex();
        void lock();

        void unlock();

    private:
        pthread_mutex_t m_mutex;
        pid_t m_pid;
    };
}


#endif //LHMILY_MUTEX_H
