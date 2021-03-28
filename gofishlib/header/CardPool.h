#ifndef CARDPOOL_H
#define CARDPOOL_H

#include "Card.h"
#include "CppCommon.h"

class CardPool{
public:
  CardPool(bool Populate);
  ~CardPool();
  bool IsFull();
  bool IsEmpty();
  void Insert(CardPtrType CardToInsert);
  CardPtrType Remove(Card CardToRemove);
  void MakeCopy(CardCollectionInternalType* PtrToCollectionToPushTo) const;
private:
  void PopulateFullPool();
  PoolOfCardsType Pool_;
};

#endif
