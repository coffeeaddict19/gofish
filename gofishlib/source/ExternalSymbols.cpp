#include "ExternalSymbols.h"
#include "Game.h"
#include "Deck.h"
#include "Card.h"
#include <memory>
#include <array>
#include <new>

//Context
void DestroyContext(Context* PtrToContext);
PlayerOutput Play(Context* PtrToContext, PlayerInput* Inputs);
CardCollection GetPlayersCopyOfCards(Context* PtrToContext, ePlayers Player);

Context NewContext(Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck], ePlayers FirstPlayer){
  Context Context;
  Context.Destroy = DestroyContext;
  Context.Play = Play;
  Context.GetPlayersCopyOfCards = GetPlayersCopyOfCards;
  Context.GamePtr_ = new(std::nothrow) Game(
    OrderOfCardsInDeck,
    FirstPlayer
  );
  return Context;
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

CardCollection GetPlayersCopyOfCards(Context* PtrToContext, ePlayers Player){
  if(nullptr == PtrToContext || nullptr == PtrToContext->GamePtr_){
    return NewCardCollection();
  }

  return reinterpret_cast<Game*>(PtrToContext->GamePtr_)->GetPlayersCopyOfCards(Player);
}
