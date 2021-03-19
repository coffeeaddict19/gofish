#include "Game.h"
#include "Card.h"
#include "CppCommon.h"
#include <new>
#include <assert.h>

Game::Game(Logger* Logger, Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck]) :
Deck_(new(std::nothrow) Deck(Logger, OrderOfCardsInDeck)),
Books_(new(std::nothrow) Books(Logger)),
Players_{{
  Player(Logger, Deck_, Books_, John),
  Player(Logger, Deck_, Books_, Dan),
  Player(Logger, Deck_, Books_, Judy),
  Player(Logger, Deck_, Books_, Danielle),
  Player(Logger, Deck_, Books_, Nicholas)
}} {
}

Game::~Game(){
}

PlayerOutput Game::Play(PlayerInput* Inputs){
  PlayerOutput Output;
  Output.Error_ = eErrors::NotImplemented;
  return Output;
}

CardCollection Game::GetPlayersCopyOfCards(ePlayers Player){
  return Players_.at(static_cast<size_t>(Player)).GetCopyOfCards();
}
