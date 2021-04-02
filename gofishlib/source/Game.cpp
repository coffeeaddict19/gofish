#include "Game.h"
#include "Card.h"
#include "CppCommon.h"
#include "spdlog/spdlog.h"
#include <new>
#include <assert.h>

Game::Game(
  Card (*OrderOfCardsInDeck)[kNumberOfCardsInDeck],
  ePlayers FirstPlayer
) :
Deck_(new(std::nothrow) Deck(OrderOfCardsInDeck)),
Books_(new(std::nothrow) Books()),
Players_{{
  Player(Deck_, Books_, John),
  Player(Deck_, Books_, Dan),
  Player(Deck_, Books_, Judy),
  Player(Deck_, Books_, Danielle),
  Player(Deck_, Books_, Nicholas)
}},
FirstPlayer_(FirstPlayer) {
  spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
  spdlog::set_level(spdlog::level::info);

  ePlayers CurrentPlayer = FirstPlayer;
  for(unsigned char PlayerCounter=0; PlayerCounter<kNumberOfPlayers; PlayerCounter++){
    //draw out cards for this player
    for(unsigned char DrawIndex=0;DrawIndex<kNumberOfCardsToDealPerPlayer;DrawIndex++){
      assert(Players_.at(static_cast<unsigned char>(CurrentPlayer)).TakeCardFromDeck());
    }
    //advance to next player
    unsigned char CurrentPlayerIndex = static_cast<unsigned char>(CurrentPlayer);
    if(CurrentPlayerIndex + 1 >= kNumberOfPlayers){
      CurrentPlayer = static_cast<ePlayers>(0);
    }else{
      CurrentPlayerIndex+=1;
      CurrentPlayer = static_cast<ePlayers>(CurrentPlayerIndex);
    }
  }
  spdlog::debug("Game() constructor");
}

Game::~Game(){
  spdlog::debug("Game() destructor");
}

PlayerOutput Game::Play(PlayerInput* Inputs){
  PlayerOutput Output;
  Output.Error_ = eErrors::NotImplemented;
  return Output;
}

CardCollection Game::GetPlayersCopyOfCards(ePlayers Player){
  return Players_.at(static_cast<size_t>(Player)).GetCopyOfCards();
}
