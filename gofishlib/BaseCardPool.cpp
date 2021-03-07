#include "BaseCardPool.h"

BaseCardPool::BaseCardPool(){
}

BaseCardPool::~BaseCardPool(){
  for(auto& Card : Pool_){
    if(Card){
      Card.reset();
    }
  }
}

bool BaseCardPool::IsFull(){
  bool OneCardNotInPool = false;
  for(const auto& Card : Pool_){
    if(Card){
      OneCardNotInPool = true;
      break;
    }
  }
  return !OneCardNotInPool;
}

bool BaseCardPool::IsEmpty(){
  bool AtLeastOneCardInPool = false;
  for(const auto& Card : Pool_){
    if(!Card){
      AtLeastOneCardInPool = true;
      break;
    }
  }
  return !AtLeastOneCardInPool;
}
