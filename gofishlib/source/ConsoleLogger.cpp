#include "ConsoleLogger.h"
#include <iostream>

void ConsoleLogger::LogError(const char* Error){
    if(nullptr == Error) return;
    std::cerr<<"Error-"<<Error<<std::endl;
}

void ConsoleLogger::LogTrace(const char* Trace){
    if(nullptr == Trace) return;
    std::cout<<"Trace-"<<Trace<<std::endl;
}
