#include "Player.h"

Player::Player(Logger* Logger, std::shared_ptr<IDeck> Deck, ePlayers PlayerName){
  Logger_ = Logger;
  Deck_ = Deck;
  PlayerName_ = PlayerName;
}

Player::Player(Player&& MovedPlayer){
  this->Logger_ = MovedPlayer.Logger_;
  this->Deck_ = MovedPlayer.Deck_;
  this->PlayerName_ = MovedPlayer.PlayerName_;
}

CardCollection Player::GetCopyOfCards(){
  CardCollection Collection = NewCardCollection();
  return Collection;
}

bool Player::TakeCardFromDeck(CardPtrType Card){
  if(!Card){
    return false;
  }
  unsigned char CardIndex = *Card.get();
  BaseCardPool::Pool_.at(CardIndex) = std::move(Card);
  return true;
}

std::stack<CardPtrType> Player::GiveCardsToOtherPlayer(Card Card){
  return std::stack<CardPtrType>();
}
