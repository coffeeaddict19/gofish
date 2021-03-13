#include "Game.h"
#include <new>

Game::Game(Logger* Logger, std::shared_ptr<IDeck> Deck) :
Deck_(Deck),
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
