#include "Books.h"
#include <assert.h>

Books::Books(){
  Pool_ = std::unique_ptr<CardPool>(new(std::nothrow) CardPool(false));
  for(auto& Count: NumberOfBooksPerPlayer_){
    Count = 0;
  }
}

void Books::TransferBook(std::array<CardPtrType, kNumberOfCardsInBook> Book, ePlayers OwningPlayer){
  for(auto& CardFromBook: Book){
    assert(CardFromBook);
    Pool_.get()->Insert(std::move(CardFromBook));
  }
  IncreasePlayerBookCount(OwningPlayer);
}

unsigned char Books::GetNumberOfBooksPlayerHas(ePlayers Player){
  return NumberOfBooksPerPlayer_.at((int)Player);
}

bool Books::AllBooksAreFilled(){
  return Pool_.get()->IsFull();
}

ePlayers Books::GetPlayerWithMostBooks(){
  ePlayers PlayerWithMostBooks = (ePlayers)0;
  unsigned char CurrentPlayerIndex = 0;
  unsigned char PlayerWithMostBooksCount = 0;
  for(const auto& ThisPlayersCount: NumberOfBooksPerPlayer_){
    if(ThisPlayersCount > PlayerWithMostBooksCount){
      PlayerWithMostBooksCount = ThisPlayersCount;
      PlayerWithMostBooks = (ePlayers)CurrentPlayerIndex;
    }
    CurrentPlayerIndex=+1;
  }
  return PlayerWithMostBooks;
}

void Books::IncreasePlayerBookCount(ePlayers Player){
  NumberOfBooksPerPlayer_.at((int)Player) =+ 1;
}
