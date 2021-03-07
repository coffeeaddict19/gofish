#ifndef IPLAYER_H
#define IPLAYER_H

#include <stack>
#include "CppCommon.h"

class IPlayer{
public:
  virtual ~IPlayer();
  virtual CardCollection GetCopyOfCards() = 0;
  virtual bool TakeCardFromDeck() = 0;
  virtual std::stack<CardPtrType> GiveCardsToOtherPlayer(Card Card) = 0;
};

#endif
