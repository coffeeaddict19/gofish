#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "ILogger.h"

class ConsoleLogger : public ILogger{
public:
    void LogError(const char* Error);
    void LogTrace(const char* Trace);
};

#endif
