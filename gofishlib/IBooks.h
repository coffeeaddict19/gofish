#ifndef IBOOKS_H
#define IBOOKS_H

#include "BaseCardPool.h"
#include "CppCommon.h"
#include "CCommon.h"
#include <array>

class IBooks : protected BaseCardPool{
public:
  virtual void TransferBook(std::array<CardPtrType, kNumberOfCardsInBook> Book, ePlayers OwningPlayer) = 0;
  virtual unsigned char GetNumberOfBooksPlayerHas(ePlayers Player) = 0;
  virtual bool AllBooksAreFilled() = 0;
  virtual ePlayers GetPlayerWithMostBooks() = 0;
};


#endif
