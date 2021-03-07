#include "Game.h"

Game::Game(Logger* Logger, std::shared_ptr<IDeck> Deck) :
Deck_(Deck),
Players_{{
  Player(Logger, Deck_, Human),
  Player(Logger, Deck_, Dan),
  Player(Logger, Deck_, Judy),
  Player(Logger, Deck_, Danielle),
  Player(Logger, Deck_, Nicholas)
}} {
}

Game::~Game(){
}
