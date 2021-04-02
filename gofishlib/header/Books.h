#ifndef BOOKS_H
#define BOOKS_H

#include "IBooks.h"
#include "CCommon.h"
#include "CardPool.h"
#include <array>
#include <memory>

class Books : public IBooks{
public:
  Books();
  void TransferBook(std::array<CardPtrType, kNumberOfCardsInBook> Book, ePlayers OwningPlayer);
  unsigned char GetNumberOfBooksPlayerHas(ePlayers Player);
  bool AllBooksAreFilled();
  ePlayers GetPlayerWithMostBooks();
private:
  void IncreasePlayerBookCount(ePlayers Player);
  std::array<unsigned char, kNumberOfPlayers> NumberOfBooksPerPlayer_;
  std::unique_ptr<CardPool> Pool_;
};


#endif
