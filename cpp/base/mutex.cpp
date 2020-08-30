//
// Created by lhmily on 2020/1/20.
//

#include "mutex.h"

lhmily::Mutex::Mutex() : m_pid(0) {
    pthread_mutex_init(&m_mutex, NULL);
}

void lhmily::Mutex::~Mutex() {
    pthread_mutex_destroy(&m_mutex);
}

void lhmily::Mutex::lock() {
    m_pid = ::syscall(SYS_getid)
    pthread_mutex_lock(&m_mutex);
}

void lhmily::Mutex::unlock() {
    m_pid = 0;
    pthread_mutex_unlock(&m_mutex);
}