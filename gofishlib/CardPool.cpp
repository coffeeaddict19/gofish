#include "CardPool.h"

CardPool::CardPool(){

}

CardPool::~CardPool(){
  for(auto& Card : Pool_){
    if(Card){
      Card.reset();
    }
  }
}

bool CardPool::IsFull(){
  bool OneCardNotInPool = false;
  for(const auto& Card : Pool_){
    if(Card){
      OneCardNotInPool = true;
      break;
    }
  }
  return !OneCardNotInPool;
}

bool CardPool::IsEmpty(){
  bool AtLeastOneCardInPool = false;
  for(const auto& Card : Pool_){
    if(!Card){
      AtLeastOneCardInPool = true;
      break;
    }
  }
  return !AtLeastOneCardInPool;
}

void CardPool::Insert(CardPtrType CardToInsert){
  Card CardIndex = *CardToInsert.get();
  Pool_.at(CardIndex) = std::move(CardToInsert);
}

CardPtrType CardPool::Remove(Card CardToRemove){
  return std::move(Pool_.at(CardToRemove));
}
