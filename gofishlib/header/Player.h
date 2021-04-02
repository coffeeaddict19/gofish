#ifndef PLAYER_H
#define PLAYER_H

#include "IPlayer.h"
#include "IDeck.h"
#include "IBooks.h"
#include "CardPool.h"
#include <memory>

class Player : public IPlayer{
public:
  Player(
    std::shared_ptr<IDeck> Deck,
    std::shared_ptr<IBooks> Books,
    ePlayers PlayerName
  );
  ~Player();
  Player(Player&& MovedPlayer);
  CardCollection GetCopyOfCards();
  bool TakeCardFromDeck();
  std::stack<CardPtrType> GiveCardsToOtherPlayer(Card Card);
private:
  std::shared_ptr<IDeck> Deck_;
  std::shared_ptr<IBooks> Books_;
  ePlayers PlayerName_;
  std::unique_ptr<CardPool> Pool_;
};

#endif
