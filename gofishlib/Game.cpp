#include "Game.h"

Game::Game(Logger* Logger, std::shared_ptr<IDeck> Deck) :
Deck_(Deck),
Books_(new Books(Logger)),
Players_{{
  Player(Logger, Deck_, Books_, Human),
  Player(Logger, Deck_, Books_, Dan),
  Player(Logger, Deck_, Books_, Judy),
  Player(Logger, Deck_, Books_, Danielle),
  Player(Logger, Deck_, Books_, Nicholas)
}} {
}

Game::~Game(){
}
