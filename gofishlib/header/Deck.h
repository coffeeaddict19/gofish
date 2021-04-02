#ifndef DECK_H
#define DECK_H

#include "IDeck.h"
#include "CardPool.h"
#include <memory>

class Deck : public IDeck{
public:
  Deck(Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck]);
  CardPtrType Draw();
private:
  std::unique_ptr<CardPool> Pool_;
  std::array<Card, kNumberOfCardsInDeck> OrderOfCardsInDeck_;
  size_t DrawIndex_;
};

#endif
