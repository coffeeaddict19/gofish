#include "Player.h"

Player::Player(
  Logger* Logger,
  std::shared_ptr<IDeck> Deck,
  std::shared_ptr<IBooks> Books,
  ePlayers PlayerName
){
  Logger_ = Logger;
  Deck_ = Deck;
  Books_ = Books;
  PlayerName_ = PlayerName;
  Pool_ = std::make_unique<CardPool>();
}

Player::Player(Player&& MovedPlayer){
  this->Logger_ = MovedPlayer.Logger_;
  this->Deck_ = MovedPlayer.Deck_;
  this->Books_ = MovedPlayer.Books_;
  this->PlayerName_ = MovedPlayer.PlayerName_;
}

CardCollection Player::GetCopyOfCards(){
  CardCollection Collection = NewCardCollection();
  return Collection;
}

bool Player::TakeCardFromDeck(){
  CardPtrType CardPtr = Deck_.get()->Draw();

  if(!CardPtr){
    return false;
  }

  Pool_.get()->Insert(std::move(CardPtr));

  return true;
}

std::stack<CardPtrType> Player::GiveCardsToOtherPlayer(Card Card){
  return std::stack<CardPtrType>();
}
