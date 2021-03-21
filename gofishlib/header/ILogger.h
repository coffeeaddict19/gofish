#ifndef ILOGGER_H
#define ILOGGER_H

class ILogger{
public:
    virtual void LogError(const char* Error) = 0;
    virtual void LogTrace(const char* Trace) = 0;
};

#endif
