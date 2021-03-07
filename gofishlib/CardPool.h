#ifndef CARDPOOL_H
#define CARDPOOL_H

#include "Card.h"
#include "CppCommon.h"

class CardPool{
public:
  CardPool();
  ~CardPool();
  bool IsFull();
  bool IsEmpty();
  void Insert(CardPtrType CardToInsert);
  CardPtrType Remove(Card CardToRemove);
private:
  PoolOfCardsType Pool_;
};

#endif
