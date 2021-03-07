#include "Logger.h"
#include "ConsoleLogger.h"

void DestroyConsoleLogger(Logger* PtrToLogger);

Logger NewConsoleLogger(){
  Logger NewLogger;
  NewLogger.LoggerPtr_ = new ConsoleLogger();
  NewLogger.Destroy = DestroyConsoleLogger;
  return NewLogger;
}

void DestroyConsoleLogger(Logger* PtrToLogger){
  if(PtrToLogger->LoggerPtr_ != nullptr){
    delete reinterpret_cast<ConsoleLogger*>(PtrToLogger->LoggerPtr_);
    PtrToLogger->LoggerPtr_ = nullptr;
  }
}
