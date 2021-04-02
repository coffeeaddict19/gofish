#include "Deck.h"

Deck::Deck(Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck]){
  Pool_ = std::unique_ptr<CardPool>(new(std::nothrow) CardPool(true));
  size_t DeckArrayIndex = 0;
  for(auto& DeckArrayPosition : OrderOfCardsInDeck_){
    DeckArrayPosition = (*OrderOfCardsInDeck)[DeckArrayIndex];
    DeckArrayIndex++;
  }
  DrawIndex_ = 0;
}

CardPtrType Deck::Draw(){
  if(Pool_){
    size_t DrawIndex = DrawIndex_;
    DrawIndex_=DrawIndex_+1;
    return Pool_.get()->Remove(OrderOfCardsInDeck_.at(DrawIndex));
  }else{
    return CardPtrType(nullptr);
  }
}
