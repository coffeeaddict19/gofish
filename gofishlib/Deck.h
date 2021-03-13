#ifndef DECK_H
#define DECK_H

#include "IDeck.h"
#include "CardPool.h"
#include <memory>

class Deck : public IDeck{
public:
  Deck(Logger* Logger);
  CardPtrType Draw();
  //todo: need either a deck sort function in here or inject one. just need to
  //pass in an array of integers (Card)
private:
  Logger* Logger_;
  std::unique_ptr<CardPool> Pool_;
};

#endif
