#include "Deck.h"

Deck::Deck(Logger* Logger) : Logger_(Logger){
  CardIndex_ = 0;
}

CardPtrType Deck::Draw(){
  if(CardIndex_ < kNumberOfCardsInDeck){
    unsigned char CurrentCardIndex = CardIndex_;
    CardIndex_+=1;
    return std::move(BaseCardPool::Pool_[CurrentCardIndex]);
  }else{
    return CardPtrType(nullptr);
  }
}
