#include "Player.h"
#include <assert.h>
#include <new>

Player::Player(
  std::shared_ptr<IDeck> Deck,
  std::shared_ptr<IBooks> Books,
  ePlayers PlayerName
){
  Deck_ = Deck;
  Books_ = Books;
  PlayerName_ = PlayerName;
  Pool_ = std::unique_ptr<CardPool>(new(std::nothrow) CardPool(false));
}

Player::Player(Player&& MovedPlayer){
  this->Deck_ = MovedPlayer.Deck_;
  this->Books_ = MovedPlayer.Books_;
  this->PlayerName_ = MovedPlayer.PlayerName_;
}

Player::~Player(){
}

CardCollection Player::GetCopyOfCards(){
  CardCollection Collection = NewCardCollection();
  if(Collection.CardCollection_ != nullptr){
    CardCollectionInternalType* PtrToCollection = reinterpret_cast<CardCollectionInternalType*>(
      Collection.CardCollection_
    );
    assert(Pool_);
    if(Pool_){
      Pool_.get()->MakeCopy(PtrToCollection);
    }
  }
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
