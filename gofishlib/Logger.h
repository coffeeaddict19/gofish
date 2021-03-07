#ifndef LOGGER_H
#define LOGGER_H

typedef void* LoggerPtr;

struct Logger{
    LoggerPtr LoggerPtr_;
    void (*Destroy)(Logger* PtrToLogger);
};

#endif
