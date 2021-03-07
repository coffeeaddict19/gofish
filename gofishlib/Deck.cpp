#include "Deck.h"

Deck::Deck(Logger* Logger) : Logger_(Logger){
  Pool_ = std::make_unique<CardPool>();
}

CardPtrType Deck::Draw(){
  CardPtrType CardPtr(nullptr);
  //todo draw
  return CardPtr;
}
