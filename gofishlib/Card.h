#ifndef CARDTYPES_H
#define CARDTYPES_H

#include "CCommon.h"

struct CardWithInitFlag{
  Card Card_;
  bool Initialized_;
};

typedef void* CardCollectionVoidPtr;

struct CardCollection{
  CardCollectionVoidPtr CardCollection_;
  void (*Destroy)(CardCollection* PtrToCardCollection);
  unsigned char (*Size)(CardCollection* PtrToCardCollection);
  CardWithInitFlag (*At)(CardCollection* PtrToCardCollection, unsigned char Index);
  void (*Push)(CardCollection* PtrToCardCollection, Card C);
};

CardCollection NewCardCollection();

struct CardCollectionWithInitFlag{
  CardCollection CardCollection_;
  bool Initialized_;
};

#endif
