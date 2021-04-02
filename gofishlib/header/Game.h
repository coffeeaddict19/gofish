#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"
#include "Books.h"
#include "CCommon.h"
#include <array>
#include <memory>

class Game{
public:
  Game(
    Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck],
    ePlayers FirstPlayer
  );
  ~Game();
  PlayerOutput Play(PlayerInput* Inputs);
  CardCollection GetPlayersCopyOfCards(ePlayers Player);
private:
  std::shared_ptr<IDeck> Deck_;
  std::shared_ptr<IBooks> Books_;
  std::array<Player, kNumberOfPlayers> Players_;
  ePlayers FirstPlayer_;
};

#endif
