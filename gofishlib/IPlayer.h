#ifndef IPLAYER_H
#define IPLAYER_H

#include <stack>
#include "BaseCardPool.h"
#include "Card.h"

class IPlayer : protected BaseCardPool{
public:
  virtual ~IPlayer();
  virtual CardCollection GetCopyOfCards() = 0;
  virtual bool TakeCardFromDeck(CardPtrType Card) = 0;
  virtual std::stack<CardPtrType> GiveCardsToOtherPlayer(Card Card) = 0;
};

#endif
