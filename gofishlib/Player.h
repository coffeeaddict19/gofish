#ifndef PLAYER_H
#define PLAYER_H

#include "IPlayer.h"
#include "IDeck.h"
#include "Logger.h"
#include <memory>

class Player : public IPlayer{
public:
  Player(Logger* Logger, std::shared_ptr<IDeck> Deck, ePlayers PlayerName);
  Player(Player&& MovedPlayer);
  CardCollection GetCopyOfCards();
  bool TakeCardFromDeck(CardPtrType Card);
  std::stack<CardPtrType> GiveCardsToOtherPlayer(Card Card);
private:
  Logger* Logger_;
  std::shared_ptr<IDeck> Deck_;
  ePlayers PlayerName_;
};

#endif
