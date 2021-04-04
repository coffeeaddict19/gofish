#include "ExternalSymbols.h"
#include "Game.h"
#include "Deck.h"
#include "Card.h"
#include <memory>
#include <array>
#include <new>
#include <set>
#include <assert.h>

//Context
void DestroyContext(Context* PtrToContext);
PlayerOutput Play(Context* PtrToContext, PlayerInput* Inputs);
CardCollection GetPlayersCopyOfCards(Context* PtrToContext, ePlayers Player);
eErrors ValidateCardsInDeck(Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck]);

Context NewContext(Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck], ePlayers FirstPlayer){
  eErrors CardsInDeckIsValid = ValidateCardsInDeck(OrderOfCardsInDeck);
  assert(NoError == CardsInDeckIsValid);
  Context Context;
  Context.Errors_ = CardsInDeckIsValid;
  Context.Destroy = DestroyContext;
  Context.Play = Play;
  Context.GetPlayersCopyOfCards = GetPlayersCopyOfCards;
  if(NoError == Context.Errors_){
    Context.GamePtr_ = new(std::nothrow) Game(
      OrderOfCardsInDeck,
      FirstPlayer
    );
  }else{
    Context.GamePtr_ = nullptr;
  }
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

eErrors ValidateCardsInDeck(Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck]){
  if(nullptr == OrderOfCardsInDeck){
    return InvalidArg;
  }
  std::set<Card> ExpectedDeck;
  ExpectedDeck.insert(*OrderOfCardsInDeck, *OrderOfCardsInDeck+kNumberOfCardsInDeck);
  if(kNumberOfCardsInDeck != ExpectedDeck.size()){
    return InvalidArg;
  }
  for(std::set<Card>::iterator it=ExpectedDeck.begin(); it!=ExpectedDeck.end(); ++it){
    if((*it)>kNumberOfCardsInDeck-1){
      return InvalidArg;
    }
  }
  return NoError;
}
