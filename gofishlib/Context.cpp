#include "ExternalSymbols.h"
#include "Game.h"
#include "Context.h"
#include "Deck.h"
#include <memory>

void Destroy(Context* PtrToContext);
void SetLogger(Context* PtrToContext, Logger* PtrToLogger);
bool IsGameOver(Context* PtrToContext);
HumanPlayerTurnOutputs PlayHumanTurn(Context* PtrToContext, HumanPlayerTurnInputs* RequestedCard);
CardCollectionWithInitFlag GetHumanCards(Context* PtrToContext);
AIPlayerTurnOutputs PlayAITurn(Context* PtrToContext);

Context NewContext(){
  Context Context;
  Context.Destroy = Destroy;
  Context.Logger_ = nullptr;
  Context.IsGameOver = IsGameOver;
  Context.PlayHumanTurn = PlayHumanTurn;
  Context.GetHumanCards = GetHumanCards;
  Context.PlayAITurn = PlayAITurn;
  Context.GamePtr_ = new Game(Context.Logger_, std::shared_ptr<IDeck>(new Deck(Context.Logger_)));
  return Context;
}

void SetLogger(Context* PtrToContext, Logger* PtrToLogger){
  PtrToContext->Logger_ = PtrToLogger;
}

void Destroy(Context* PtrToContext){
  Game* GamePtr = reinterpret_cast<Game*>(PtrToContext->GamePtr_);
  if(GamePtr != nullptr){
    delete GamePtr;
    PtrToContext->GamePtr_ = nullptr;
  }
}

bool IsGameOver(Context* PtrToContext){
  return false;
}

HumanPlayerTurnOutputs PlayHumanTurn(Context* PtrToContext, HumanPlayerTurnInputs* RequestedCard){
  HumanPlayerTurnOutputs outputs;
  outputs.Error_ = eErrors::NotImplemented;
  return outputs;
}

AIPlayerTurnOutputs PlayAITurn(Context* PtrToContext){
  AIPlayerTurnOutputs outputs;
  outputs.Error_ = eErrors::NotImplemented;
  return outputs;
}

CardCollectionWithInitFlag GetHumanCards(Context* PtrToContext){
  CardCollectionWithInitFlag Collection;
  Collection.Initialized_ = false;
  return Collection;
}
