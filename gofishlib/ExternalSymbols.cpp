#include "ExternalSymbols.h"
#include "ConsoleLogger.h"
#include "Game.h"
#include "Deck.h"
#include <memory>
#include <new>

//Console Logger
void DestroyConsoleLogger(Logger* PtrToLogger);

Logger NewConsoleLogger(){
  Logger NewLogger;
  NewLogger.LoggerPtr_ = new(std::nothrow) ConsoleLogger();
  NewLogger.Destroy = DestroyConsoleLogger;
  return NewLogger;
}

void DestroyConsoleLogger(Logger* PtrToLogger){
  if(PtrToLogger->LoggerPtr_ != nullptr){
    delete reinterpret_cast<ConsoleLogger*>(PtrToLogger->LoggerPtr_);
    PtrToLogger->LoggerPtr_ = nullptr;
  }
}

//Context
void DestroyContext(Context* PtrToContext);
void SetLoggerToContext(Context* PtrToContext, Logger* PtrToLogger);
PlayerOutput Play(Context* PtrToContext, PlayerInput* Inputs);

Context NewContext(){
  Context Context;
  Context.Destroy = DestroyContext;
  Context.Logger_ = nullptr;
  Context.Play = Play;
  Context.SetLogger = SetLoggerToContext;
  Context.GamePtr_ = new(std::nothrow) Game(
    Context.Logger_,
    std::shared_ptr<IDeck>(new(std::nothrow) Deck(Context.Logger_))
  );
  return Context;
}

void SetLoggerToContext(Context* PtrToContext, Logger* PtrToLogger){
  PtrToContext->Logger_ = PtrToLogger;
}

void DestroyContext(Context* PtrToContext){
  Game* GamePtr = reinterpret_cast<Game*>(PtrToContext->GamePtr_);
  if(GamePtr != nullptr){
    delete GamePtr;
    PtrToContext->GamePtr_ = nullptr;
  }
}

PlayerOutput Play(Context* PtrToContext, PlayerInput* Inputs){
  if(nullptr == PtrToContext){
    PlayerOutput Output;
    Output.Error_ = eErrors::InvalidArg;
    return Output;
  }

  return reinterpret_cast<Game*>(PtrToContext)->Play(Inputs);
}
