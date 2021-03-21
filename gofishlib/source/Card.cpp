#include "Card.h"
#include "CppCommon.h"
#include <vector>
#include <new>

void Destroy(CardCollection* PtrToCardCollection);
CardWithInitFlag At(CardCollection* PtrToCardCollection, unsigned char Index);
unsigned char Size(CardCollection* PtrToCardCollection);
void Push(CardCollection* PtrToCardCollection, Card C);

CardCollection NewCardCollection(){
  CardCollection Collection;
  Collection.At = At;
  Collection.Destroy = Destroy;
  Collection.Size = Size;
  Collection.CardCollection_ = new(std::nothrow) CardCollectionInternalType();
  Collection.Push = Push;
  return Collection;
}

void Destroy(CardCollection* PtrToCardCollection){
  if(nullptr == PtrToCardCollection) return;
  if(nullptr == PtrToCardCollection->CardCollection_) return;
  auto PtrToCards = reinterpret_cast<CardCollectionInternalType*>(
    PtrToCardCollection->CardCollection_
  );
  delete PtrToCards;
  PtrToCardCollection->CardCollection_ = nullptr;
}

void Push(CardCollection* PtrToCardCollection, Card C){
  if(nullptr == PtrToCardCollection) return;
  if(nullptr == PtrToCardCollection->CardCollection_) return;
  auto PtrToCards = reinterpret_cast<CardCollectionInternalType*>(
    PtrToCardCollection->CardCollection_
  );
  PtrToCards->push_back(C);
}

CardWithInitFlag At(CardCollection* PtrToCardCollection, unsigned char Index){
  CardWithInitFlag Result{0};
  Result.Initialized_ = false;
  if(nullptr == PtrToCardCollection) return Result;
  if(nullptr == PtrToCardCollection->CardCollection_) return Result;
  auto PtrToCards = reinterpret_cast<CardCollectionInternalType*>(
    PtrToCardCollection->CardCollection_
  );
  if(!(Index < PtrToCards->size())){
    return Result;
  }
  Result.Initialized_ = true;
  Result.Card_ = PtrToCards->at(Index);
  return Result;
}

unsigned char Size(CardCollection* PtrToCardCollection){
  if(nullptr == PtrToCardCollection) return 0;
  if(nullptr == PtrToCardCollection->CardCollection_) return 0;
  auto PtrToCards = reinterpret_cast<CardCollectionInternalType*>(
    PtrToCardCollection->CardCollection_
  );
  return static_cast<unsigned char>(PtrToCards->size());
}