#include "Deck.h"

Deck::Deck(Logger* Logger, Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck]) :
Logger_(Logger){
  Pool_ = std::make_unique<CardPool>();
  size_t DeckArrayIndex = 0;
  for(auto& DeckArrayPosition : OrderOfCardsInDeck_){
    DeckArrayPosition = *OrderOfCardsInDeck[DeckArrayIndex];
    DeckArrayIndex++;
  }
  DrawIndex_ = 0;
}

CardPtrType Deck::Draw(){
  if(Pool_.get()){
    size_t DrawIndex = DrawIndex_;
    DrawIndex_+=1;
    return Pool_.get()->Remove(DrawIndex);
  }else{
    return CardPtrType(nullptr);
  }
}
