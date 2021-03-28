#include "CardPool.h"
#include <assert.h>
#include <new>

CardPool::CardPool(bool Populate){
  if(Populate){
    PopulateFullPool();
  }
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
  if(CardToRemove < Pool_.size()){
    return std::move(Pool_.at(CardToRemove));
  }else{
    return CardPtrType(nullptr);
  }
}

void CardPool::MakeCopy(CardCollectionInternalType* PtrToCollectionToPushTo) const{
  assert(PtrToCollectionToPushTo != nullptr);
  if(PtrToCollectionToPushTo != nullptr){
    for(const auto& PtrInPool : Pool_){
      if(PtrInPool){
        PtrToCollectionToPushTo->push_back(*PtrInPool.get());
      }
    }
  }
}

void CardPool::PopulateFullPool(){
  Card CurrentCard = 0;
  for(auto& ThisCard : Pool_){
    ThisCard = std::unique_ptr<Card>(new(std::nothrow)Card(CurrentCard));
    CurrentCard=CurrentCard+1;
  }
}
