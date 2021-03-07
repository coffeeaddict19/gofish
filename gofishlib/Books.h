#ifndef BOOKS_H
#define BOOKS_H

#include "IBooks.h"
#include "CCommon.h"
#include "ILogger.h"
#include <array>

class Books : public IBooks{
public:
  Books(ILogger* Logger);
  void TransferBook(std::array<CardPtrType, kNumberOfCardsInBook> Book, ePlayers OwningPlayer);
  unsigned char GetNumberOfBooksPlayerHas(ePlayers Player);
  bool AllBooksAreFilled();
  ePlayers GetPlayerWithMostBooks();
private:
  void IncreasePlayerBookCount(ePlayers Player);
  std::array<unsigned char, kNumberOfPlayers> NumberOfBooksPerPlayer_;
  ILogger* Logger_;
};


#endif
